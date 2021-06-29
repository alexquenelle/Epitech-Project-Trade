/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** Strategie
*/

#ifndef STRATEGIE_HPP_
#define STRATEGIE_HPP_

#include "manager.hpp"
#include "Crypto.hpp"
#include "Settings.hpp"

void run_strategie(Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH, Settings *settings);
double get_amount_crypto(Crypto *crypto, float percent_of_usdt, value pair);

#endif /* !STRATEGIE_HPP_ */