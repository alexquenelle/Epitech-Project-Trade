/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** main
*/

#include "Settings.hpp"
#include "Crypto.hpp"
#include "manager.hpp"

double BTC_BALANCE = 0;
double USDT_BALANCE = 1000;
double ETH_BALANCE = 0;

int main(int argc, char **argv)
{
    Settings *settings = new Settings;
    Crypto *USDT_BTC = new Crypto;
    Crypto *USDT_ETH = new Crypto;
    Crypto *BTC_ETH = new Crypto;

    for (std::string line; std::getline(std::cin, line);) { 
        manager(line, settings, USDT_BTC, USDT_ETH, BTC_ETH);
    }
    return (0);
}