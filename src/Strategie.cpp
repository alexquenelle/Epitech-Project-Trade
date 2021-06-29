/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** Strategie
*/

#include <Indicators.hpp>
#include "Strategie.hpp"

extern double BTC_BALANCE;
extern double USDT_BALANCE;
extern double ETH_BALANCE;

double get_amount_crypto(Crypto *crypto, float how_much, value pair)
{
    double crypto_currency = 0;

    if (pair == value::USDT_BTC)
        crypto_currency = (USDT_BALANCE * how_much) / 100;
    else if (pair == value::USDT_ETH)
        crypto_currency = (USDT_BALANCE * how_much) / 100;
    else
        crypto_currency = (BTC_BALANCE * how_much) / 100;

    return (crypto_currency / crypto->get_close()[crypto->get_close().size() - 1]);
}

double total_average(std::vector<float> list)
{
    double average;

	for (int inc = 0; inc < list.size(); ++inc){
        average += list[inc];
    }

    return (average/list.size());
}

bool is_trend_up(int n, std::vector<float> list)
{
    std::vector<float> new_list(list.end() - n, list.end());
    float maybe_to_buy = list[list.size()];
    print_vector_float(new_list);

    if (total_average(new_list) < maybe_to_buy)
        return true;
    else
        return false;
}

bool need_to_buy(Crypto *pair, double percentage_to_buy, value enum_pair)
{
    if (pair->get_holding_position() == 0
        && get_amount_crypto(pair, percentage_to_buy, enum_pair) > 0){
        return true;
    } else {
        return false;
    }
}

bool need_to_sell(Crypto *pair)
{
    if (pair->get_holding_position() <= pair->get_close()[pair->get_close().size() - 1]){
        return true;
    } else {
        return false;
    }
}

void buy_low_sell_high(Crypto *pair, Settings *settings, value enum_pair, double to_sell)
{
    double percentage_to_buy = 85;

    if (need_to_buy(pair, percentage_to_buy, enum_pair) == true){
        std::cerr << "BUY" << std::endl;
        pair->buy(get_amount_crypto(pair, percentage_to_buy, enum_pair), enum_pair, settings, percentage_to_buy);
    } else if (need_to_sell(pair) == true){
        if (enum_pair == value::USDT_BTC)
            pair->sell(BTC_BALANCE, enum_pair, settings);
        else if (enum_pair == value::USDT_ETH)
            pair->sell(ETH_BALANCE, enum_pair, settings);
        else if (enum_pair == value::BTC_ETH)
            pair->sell(ETH_BALANCE, enum_pair, settings);
    }
}

static void boll_strat(Crypto *pair, Settings *settings, value enum_pair, double to_sell)
{
    double percentage_to_buy = 85;

    std::tuple<float, float> bands = Indicator::BollingerBands(pair, 20);
    float current_price = pair->get_close()[pair->get_close().size() - 1];

    if (pair->get_high()[pair->get_high().size() - 1] > std::get<0>(bands)){
        // std::cerr << "SELL" << std::endl;
        if (enum_pair == value::USDT_BTC && BTC_BALANCE > 0.000001)
            pair->sell(BTC_BALANCE, enum_pair, settings);
        else if (enum_pair == value::USDT_ETH && ETH_BALANCE > 0.000001)
            pair->sell(ETH_BALANCE, enum_pair, settings);
        else if (enum_pair == value::BTC_ETH && ETH_BALANCE > 0.000001)
            pair->sell(ETH_BALANCE, enum_pair, settings);
    } else if (pair->get_low()[pair->get_low().size() - 1] < std::get<1>(bands) && get_amount_crypto(pair, percentage_to_buy, enum_pair) > 0.000001){
        pair->buy(get_amount_crypto(pair, percentage_to_buy, enum_pair) , enum_pair, settings, percentage_to_buy);
    }
    else
        return; // do nothing
}

void run_strategie(Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH, Settings *settings)
{
    boll_strat(USDT_BTC, settings, value::USDT_BTC, BTC_BALANCE);
    boll_strat(USDT_ETH, settings, value::USDT_ETH, ETH_BALANCE);
    boll_strat(BTC_ETH, settings, value::BTC_ETH, ETH_BALANCE);

    if (settings->get_actions_to_send().empty())
        USDT_BTC->do_nothing();
    else{
        std::cout << settings->get_actions_to_send() << std::endl;
    }
    settings->clear_order();
}