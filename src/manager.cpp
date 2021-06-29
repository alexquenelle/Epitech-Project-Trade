/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** manager
*/

#include "manager.hpp"

extern double BTC_BALANCE;
extern double USDT_BALANCE;
extern double ETH_BALANCE;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::vector<std::string> string_to_vector(std::string s, char c)
{
    std::string temp = "";
    std::vector<std::string> v;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c) {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(s[i]);
        }
    }
    v.push_back(temp);  
    return(v);
}

void print_vector_string(std::vector<std::string> v)
{
	for (int inc = 0; inc < v.size(); ++inc)
		std::cerr << v[inc] << std::endl;
	std::cerr << "\n";
}

void print_vector_float(std::vector<float> v)
{
    for (int inc = 0; inc < v.size(); ++inc)
		std::cerr << v[inc] << std::endl;
	std::cerr << "\n";
}

int get_api_return(const std::vector<std::string> v)
{
    if (std::strcmp(v[0].c_str(), "settings") == 0)
        return (1);
    else if (std::strcmp(v[v.size() - 2].c_str(), "order") == 0)
        return (2);
    else if (std::strcmp(v[v.size() - 2].c_str(), "next_candles") == 0)
        return (3);
    else if (std::strcmp(v[v.size() - 2].c_str(), "stacks") == 0)
        return (4);
    else
        return (-1);
}

void manager(const std::string to_parse, Settings *settings, Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH)
{
    std::vector<std::string> input_values = string_to_vector(to_parse, ' ');

        switch(get_api_return(input_values)) {
            case 1:
                fill_settings(settings, input_values[1].c_str(), input_values[2].c_str());
                break;
            case 2:
                run_strategie(USDT_BTC, USDT_ETH, BTC_ETH, settings);
                break;
            case 3:
                detect_crypto(USDT_BTC, USDT_ETH, BTC_ETH, input_values[input_values.size() - 1], settings);
                break;
            case 4:
                update_balance(string_to_vector(to_parse, ' ')[string_to_vector(to_parse, ' ').size() - 1], USDT_BTC, USDT_ETH, BTC_ETH);
                break;
        }
}

void update_balance(std::string all_balances, Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH)
{
    std::vector<std::string> each_balance = string_to_vector(all_balances, ',');

    for (int inc = 0; inc != each_balance.size(); inc++){
        if (string_to_vector(each_balance[inc], ':')[0] == "BTC")
            BTC_BALANCE = std::stod(string_to_vector(each_balance[inc], ':')[1]);
        else if (string_to_vector(each_balance[inc], ':')[0] == "ETH")
            USDT_BALANCE = std::stod(string_to_vector(each_balance[inc], ':')[1]);
        else if (string_to_vector(each_balance[inc], ':')[0] == "USDT")
            USDT_BALANCE = std::stod(string_to_vector(each_balance[inc], ':')[1]);
    }
}

void detect_crypto(Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH, std::string to_parse, Settings *settings)
{
    std::vector<std::string> data = string_to_vector(to_parse, ';');
    std::vector<std::string> pair;
    std::vector<std::string> to_analyse{"BTC_ETH", "USDT_ETH", "USDT_BTC"};
    int indicator = 0;

    for (int inc = 0; inc != data.size(); inc++){
        pair = string_to_vector(data[inc], ',');
        indicator = search_cmd(to_analyse, pair[search_cmd(settings->get_candle_format(), "pair")]);
        switch(indicator) {
            case 0:
                set_crypto(BTC_ETH, settings, pair);
                break;
            case 1:
                set_crypto(USDT_ETH, settings, pair);
                break;
            case 2:
                set_crypto(USDT_BTC, settings, pair);
                break;
        }
    }
}

void set_crypto(Crypto *crypto_to_set, Settings *settings, std::vector<std::string> data)
{
    std::vector<std::string> format = settings->get_candle_format();

    for(int inc = 0; inc != settings->get_candle_format().size(); inc++){
        if (format[inc] == "date")
            crypto_to_set->set_date(std::stof(data[inc]));
        else if (format[inc] == "high")
            crypto_to_set->set_high(std::stof(data[inc]));
        else if (format[inc] == "low")
            crypto_to_set->set_low(std::stof(data[inc]));
        else if (format[inc] == "open")
            crypto_to_set->set_open(std::stof(data[inc]));
        else if (format[inc] == "close")
            crypto_to_set->set_close(std::stof(data[inc]));
        else if (format[inc] == "volume")
            crypto_to_set->set_volume(std::stof(data[inc]));
    }
}

int search_cmd(std::vector<std::string> to_analyze, std::string cmd)
{
    for (int inc = 0; inc < to_analyze.size(); inc++){
        if (std::strcmp(to_analyze[inc].c_str(), cmd.c_str()) == 0){
            return (inc);
        }
    }
    return (-1);
}

void fill_settings(Settings *settings, std::string cmd, std::string new_value)
{
    std::vector<std::string> to_analyze{"player_names", "your_bot", "timebank",
    "time_per_move", "candle_interval", "candle_format", "candles_total",
    "candles_given", "initial_stack", "transaction_fee_percent"};

    int indicator = search_cmd(to_analyze, cmd);

    switch(indicator) {
        case 0:
            settings->set_player_names(new_value);
            break;
        case 1:
            settings->set_your_bot(new_value);
            break;
        case 2:
            settings->set_timebank(stoi(new_value));
            break;
        case 3:
            settings->set_time_per_move(stoi(new_value));
            break;
        case 4:
            settings->set_candle_interval(stoi(new_value));
            break;
        case 5:
            settings->set_candle_format(string_to_vector(new_value ,','));
            break;
        case 6:
            settings->set_candles_total(stoi(new_value));
            break;
        case 7:
            settings->set_candles_given(stoi(new_value));
            break;
        case 8:
            settings->set_initial_stack(stoi(new_value));
            break;
        case 9:
            settings->set_transaction_fee_percent(std::stof(new_value));
            break;
    }
}