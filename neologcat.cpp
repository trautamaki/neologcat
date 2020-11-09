#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
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

int getColorCode(std::string s) {
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

int main() {
    system("adb logcat -c");
    FILE* pipe = _popen("adb logcat", "r");
    if (!pipe) throw std::runtime_error("Opening adb failed!");
    try {
        std::string r = "";
        while (char c = fgetc(pipe)) {
            r += c;
            if (c == '\n') {
                std::vector<std::string> parts = split(r, " ");
                if (parts.size() > 0) {
                    if (parts[0].size() > 0 && parts[0][0] == '-') {
                        std::cout << "\x1B[96m";
                        std::cout << r;
                        std::cout << "\033[0m";
                    }
                    else {
                        bool codeReached = false;
                        int color = 0;
                        for (std::string part : parts) {
                            if (!codeReached && part.size() == 1) {
                                color = getColorCode(part);
                                codeReached = true;
                                if (color == -1)
                                    codeReached = false;
                            }
                            if (codeReached) {
                                std::cout << "\x1B[" << color << "m";
                                std::cout << part;
                                std::cout << "\033[0m";
                            }
                            else {
                                std::cout << "\x1B[37m";
                                std::cout << part;
                                std::cout << "\033[0m";
                            }
                            if (part.find("\n") == std::string::npos) {
                                std::cout << " ";
                            }
                        }
                    }
                }
                r = "";
            }
        }
    }
    catch (...) {
        _pclose(pipe);
        throw;
    }
    _pclose(pipe);
    return 0;
}

