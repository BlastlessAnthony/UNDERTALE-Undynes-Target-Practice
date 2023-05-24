#pragma once
#include <string>
#include <cstdint>
#include <cstdlib>
#include <random>
#include <algorithm>

std::string generateRandomString(uint64_t length) {
    std::string charmap = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    auto generator = [&]() {return charmap[std::rand()%charmap.length()]; };
    std::string result;
    result.reserve(length);
    std::generate_n(std::back_inserter(result), length, generator);
    return result;
}