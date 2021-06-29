/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** Crypto
*/

#ifndef CRYPTO_HPP_
#define CRYPTO_HPP_

#include <vector>
#include <iostream> 
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "Settings.hpp"

enum value {
    USDT_BTC,
    USDT_ETH,
    BTC_ETH
};

enum actions {
    SELL,
    BUY
};

class Crypto {
    public:
        Crypto();
        ~Crypto();
        // SETTERS
        void set_date(float new_date);
        void set_high(float new_high);
        void set_low(float new_low);
        void set_open(float open);
        void set_close(float new_close);
        void set_volume(float new_volume);
        void set_holding_position(double new_pos);
        // GETTERS
        std::vector<float> get_date(void);
        std::vector<float> get_high(void);
        std::vector<float> get_low(void);
        std::vector<float> get_open(void);
        std::vector<float> get_close(void);
        std::vector<float> get_volume(void);
        double get_holding_position(void);
        // ACTIONS
        int sell(double how_much, value pair, Settings *settings);
        int buy(double how_much, value pair, Settings *settings, double percentage_to_buy);
        void do_nothing();
    protected:
        std::vector<float> date;
        std::vector<float> high;
        std::vector<float> low;
        std::vector<float> open;
        std::vector<float> close;
        std::vector<float> volume;
        // value pair;
        double holding_position;
    private:
};

#endif /* !CRYPTO_HPP_ */