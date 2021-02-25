#include "utils.h"

int utils::getColorCode(char c) {
    int msgType = stringToMsgType(c);
    switch (msgType) {
        case VERBOSE:
            return 94;
        case DEBUG:
            return 95;
        case INFO:
            return 94;
        case WARNING:
            return 93;
        case ERROR:
            return 91;
        case FATAL:
            return 31;
        default:
            return -1;
    }
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

int utils::stringToMsgType(char c) {
    c = toupper(c);
    switch (c) {
        case 'V':
            return VERBOSE;
        case 'D':
            return DEBUG;
        case 'I':
            return INFO;
        case 'W':
            return WARNING;
        case 'E':
            return ERROR;
        case 'F':
            return FATAL;
        default:
            return -1;
    }
}
