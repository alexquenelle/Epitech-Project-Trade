/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** Crypto
*/

#include "Crypto.hpp"
#include "manager.hpp"

extern double BTC_BALANCE;
extern double USDT_BALANCE;
extern double ETH_BALANCE;

Crypto::Crypto()
{
    this->holding_position = 0;
}

Crypto::~Crypto()
{
}

//SETTERS

void Crypto::set_date(float new_date)
{
    this->date.push_back(new_date);
}

void Crypto::set_high(float new_high)
{
    this->high.push_back(new_high);
}

void Crypto::set_low(float new_low)
{
    this->low.push_back(new_low);
}

void Crypto::set_open(float new_open)
{
    this->open.push_back(new_open);
}

void Crypto::set_close(float new_close)
{
    this->close.push_back(new_close);
}

void Crypto::set_volume(float new_volume)
{
    this->volume.push_back(new_volume);
}

void Crypto::set_holding_position(double new_pos)
{
    if (new_pos != 0)
        this->holding_position = this->holding_position + new_pos;
    else
        this->holding_position = new_pos;
}

// GETTERS

std::vector<float> Crypto::get_date(void)
{
    return (this->date);
}

std::vector<float> Crypto::get_high(void)
{
    return (this->high);
}

std::vector<float> Crypto::get_low(void)
{
    return (this->low);
}

std::vector<float> Crypto::get_open(void)
{
    return (this->open);
}

std::vector<float> Crypto::get_close(void)
{
    return (this->close);
}

std::vector<float> Crypto::get_volume(void)
{
    return (this->volume);
}

double Crypto::get_holding_position(void)
{
    return (this->holding_position);
}

// ACTIONS

int Crypto::sell(double how_much, value pair, Settings *settings)
{
    std::ostringstream string_value;
    FORMAT_DOUBLE(string_value, "%.08f", how_much);

    if (pair == value::BTC_ETH && ETH_BALANCE > 0){
        ETH_BALANCE = ETH_BALANCE - how_much;
        settings->set_actions_to_send("sell BTC_ETH ");
        settings->set_actions_to_send(string_value.str());
        set_holding_position(0);
        settings->set_actions_to_send(";");
        return (0);
    } else if (pair == value::USDT_ETH && ETH_BALANCE > 0){
        ETH_BALANCE = ETH_BALANCE - how_much;
        settings->set_actions_to_send("sell USDT_ETH ");
        settings->set_actions_to_send(string_value.str());
        set_holding_position(0);
        settings->set_actions_to_send(";");
        return (0);
    } else if (pair == value::USDT_BTC && BTC_BALANCE > 0){
        BTC_BALANCE = BTC_BALANCE - how_much;
        settings->set_actions_to_send("sell USDT_BTC ");
        settings->set_actions_to_send(string_value.str());
        set_holding_position(0);
        settings->set_actions_to_send(";");
        return (0);
    }
    return (-1);
}

int Crypto::buy(double how_much, value pair, Settings *settings, double percentage_to_buy)
{   
    std::ostringstream string_value;
    FORMAT_DOUBLE(string_value, "%.08f", how_much);
    double fee = how_much * 0.02;

    if (pair == value::BTC_ETH){
        BTC_BALANCE = BTC_BALANCE - (((BTC_BALANCE * percentage_to_buy) / 100) + fee);
        settings->set_actions_to_send("buy BTC_ETH ");
        settings->set_actions_to_send(string_value.str());
        this->set_holding_position(this->get_close()[get_close().size() - 1]);
        settings->set_actions_to_send(";");
        return(0);
    }
    else if (pair == value::USDT_ETH){
        USDT_BALANCE = USDT_BALANCE - (((USDT_BALANCE * percentage_to_buy) / 100) + fee);
        settings->set_actions_to_send("buy USDT_ETH ");
        settings->set_actions_to_send(string_value.str());
        this->set_holding_position(this->get_close()[get_close().size() - 1]);
        settings->set_actions_to_send(";");
        return(0);
    }
    else if (pair == value::USDT_BTC){
        // std::cerr << "--------- inside USDT_BTC !!" << std::endl;
        USDT_BALANCE = USDT_BALANCE - (((USDT_BALANCE * percentage_to_buy) / 100) + fee);
        // std::cerr << "updated balance 2 => " << USDT_BALANCE << std::endl;
        settings->set_actions_to_send("buy USDT_BTC ");
        settings->set_actions_to_send(string_value.str());
        this->set_holding_position(this->get_close()[get_close().size() - 1]);
        settings->set_actions_to_send(";");
        return(0);
    }
    return (-1);
}

void Crypto::do_nothing()
{
    std::cout << "pass" << std::endl;
}