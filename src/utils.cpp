#include "utils.h"

int utils::getColorCode(std::string s) {
    if (s == "D") {
        return 95;
    }
    else if (s == "W") {
        return 93;
    }
    else if (s == "E") {
        return 91;
    }
    else if (s == "F") {
        return 31;
    }
    else if (s == "I") {
        return 94;
    }
    return -1;
}

std::vector<std::string> utils::split(const std::string& str, const std::string& delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}