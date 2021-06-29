/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** Indicators.cpp file
*/

#include <Crypto.hpp>
#include <algorithm>
#include <cmath>
#include <manager.hpp>

#include "Indicators.hpp"

template<typename T>
static std::vector<T> getValuesInRange(std::vector<T> values, int count
)
{

    int size = values.size();
    if (size < count)
        return values;
    std::vector<T> ret;
    std::reverse(values.begin(), values.end());
    for (auto it = values.begin(); it != values.end() && count; count--, it++) {
        ret.push_back(*it);
    }
    return ret;
}

double Indicator::MovingAverage(std::vector<float> input, int samplingRange)
{
    std::vector<float> values = getValuesInRange(input, samplingRange);
    if (values.empty())
        return 0; // error
    double average = 0.0f;
    for (double value : values){
        average += value;
    }

    return average / samplingRange;
}

static float standard_dev(std::vector<float> values)
{
    float ret = 0.0f;
    float mean = Indicator::MovingAverage(values, values.size());

    for (auto value: values){
        ret += pow(value - mean, 2);
    }

    return (sqrt(ret));
}

std::tuple<float, float> Indicator::BollingerBands(Crypto *pair, int
samplingRange
)
{
    std::vector<float> hi = getValuesInRange(pair->get_high(), samplingRange);
    std::vector<float> lo = getValuesInRange(pair->get_low(), samplingRange);;
    std::vector<float> close = getValuesInRange(pair->get_close(),
        samplingRange);

    std::reverse(hi.begin(), hi.end());
    std::reverse(lo.begin(), lo.end());
    std::reverse(close.begin(), close.end());

    std::vector<float> TP;

    for (std::size_t i = 0; i < hi.size(); ++i){
        TP.push_back((hi[i] + lo[i] + close[i]) / 3);
    }

    float dev = standard_dev(TP);

    float BOLU = MovingAverage(TP, samplingRange) + (dev * 0.1);
    float BOLD = MovingAverage(TP, samplingRange) - (dev * 0.1);

    return {BOLU, BOLD};
}