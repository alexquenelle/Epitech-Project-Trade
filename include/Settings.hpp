/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** trade
*/

#ifndef TRADE_HPP_
#define TRADE_HPP_

#include <iostream> 
#include <string>
#include <vector>

class Settings {
    public:
        Settings();
        ~Settings();
        // SETTERS
        void set_player_names(std::string new_player_name);
        void set_your_bot(std::string new_bot_name);
        void set_timebank(int new_timebank);
        void set_time_per_move(int new_time_per_move);
        void set_candle_interval(int new_candle_interval);
        void set_candle_format(std::vector<std::string> new_candle_format);
        void set_candles_total(int new_candles_total);
        void set_candles_given(int new_candles_given);
        void set_initial_stack(int new_initial_stack);
        void set_transaction_fee_percent(float new_transaction_fee_percent);
        void set_actions_to_send(std::string new_to_add);
        // GETTERS
        std::string get_player_names(void);
        std::string get_bot_name(void);
        int get_timebank(void);
        int get_time_per_move(void);
        int get_candle_interval(void);
        std::vector<std::string> get_candle_format(void);
        int get_candles_total(void);
        int get_candles_given(void);
        int get_initial_stack(void);
        float get_transaction_fee_percent(void);
        std::string get_actions_to_send(void);
        // ACTIONS
        void clear_order(void);
    protected:
        std::vector<std::string> candle_format;
        int candle_interval;
        int candles_total;
        int candles_given;
        int initial_stack;
        float transaction_fee_percent;
        int timebank;
        int time_per_move;
        std::string player_name;
        std::string bot_name;
        std::string to_send;
    private:
};

#endif /* !TRADE_HPP_ */