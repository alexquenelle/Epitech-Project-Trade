/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** trade
*/

#include "Settings.hpp"

Settings::Settings()
{
}

Settings::~Settings()
{
}

// SETTERS

void Settings::set_player_names(std::string new_player_name)
{
    this->player_name = new_player_name;
}

void Settings::set_your_bot(std::string new_bot_name)
{
    this->bot_name = new_bot_name;
}

void Settings::set_timebank(int new_timebank)
{
    this->timebank = new_timebank;
}

void Settings::set_time_per_move(int new_time_per_move)
{
    this->time_per_move = new_time_per_move;
}

void Settings::set_candle_interval(int new_candle_interval)
{
    this->candle_interval = new_candle_interval;
}

void Settings::set_candle_format(std::vector<std::string> new_candle_format)
{
    this->candle_format = new_candle_format;
}

void Settings::set_candles_total(int new_candles_total)
{
    this->candles_total = new_candles_total;
}

void Settings::set_candles_given(int new_candles_given)
{
    this->candles_given = new_candles_given;
}

void Settings::set_initial_stack(int new_initial_stack)
{
    this->initial_stack = new_initial_stack;
}

void Settings::set_transaction_fee_percent(float new_transaction_fee_percent)
{
    this->transaction_fee_percent = 1 + new_transaction_fee_percent;
}

void Settings::set_actions_to_send(std::string new_to_add)
{
    this->to_send.append(new_to_add);
}

// GETTERS

std::string Settings::get_player_names(void)
{
    return (this->player_name);
}

std::string Settings::get_bot_name(void)
{
    return (this->bot_name);
}

int Settings::get_timebank(void)
{
    return (this->timebank);
}

int Settings::get_time_per_move(void)
{
    return (this->time_per_move);
}

int Settings::get_candle_interval(void)
{
    return (this->candle_interval);
}

std::vector<std::string> Settings::get_candle_format(void)
{
    return (this->candle_format);
}

int Settings::get_candles_total(void)
{
    return(this->candles_total);
}

int Settings::get_candles_given(void)
{
    return (this->candles_given);
}

int Settings::get_initial_stack(void)
{
    return (this->initial_stack);
}

float Settings::get_transaction_fee_percent(void)
{
    return (this->transaction_fee_percent);
}

std::string Settings::get_actions_to_send(void)
{
    return (this->to_send);
}

// ACTIONS

void Settings::clear_order(void)
{
    this->to_send.clear();
}