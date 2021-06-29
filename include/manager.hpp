/*
** EPITECH PROJECT, 2021
** B-CNA-410-BDX-4-1-trade-alexandre.quenelle
** File description:
** manager
*/

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>

#include "Settings.hpp"
#include "Crypto.hpp"
#include "Strategie.hpp"

    #define FORMAT_DOUBLE(output, format_str, ...) \
        {char *buffer = NULL; \
            asprintf(&buffer, format_str, __VA_ARGS__);\
        output << std::string(buffer);\
        free(buffer);\
    } output\

void manager(const std::string to_parse, Settings *settings, Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH);
bool is_number(const std::string& s);
std::vector<std::string> string_to_vector(std::string s, char c);
void print_vector_string(std::vector<std::string> v);
void print_vector_float(std::vector<float> v);
void fill_settings(Settings *settings, std::string cmd, std::string new_value);
int get_api_return(const std::vector<std::string> v);
void detect_crypto(Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH, std::string to_parse);
int search_cmd(std::vector<std::string> to_analyze, std::string cmd);
void detect_crypto(Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH, std::string to_parse, Settings *settings);
void set_crypto(Crypto *crypto_to_set, Settings* settings);
void set_crypto(Crypto *crypto_to_set, Settings *settings, std::vector<std::string> data);
void update_balance(const std::string to_parse, Crypto *USDT_BTC, Crypto *USDT_ETH, Crypto *BTC_ETH);

#endif /* !MANAGER_HPP_ */