/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** Indicators.hpp file
*/

#ifndef B_CNA_410_BDX_4_1_TRADE_ALEXANDRE_QUENELLE_INDICATORS_HPP
#define B_CNA_410_BDX_4_1_TRADE_ALEXANDRE_QUENELLE_INDICATORS_HPP

#include <memory>
#include <vector>
#include <Crypto.hpp>

class Indicator {
    public:
    static double MovingAverage(std::vector<float> input, int samplingRange) ;

    static std::tuple<float, float> BollingerBands(Crypto *pair, int
    samplingRange);

    private:
    Indicator(){} // empecher la construction
};

#endif