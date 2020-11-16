#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "reader.h"
#include "utils.h"

int main() {
    reader r("adb logcat");
    while (true) {
        std::string s = r.readLine();
        if (s != "") {
            std::vector<std::string> parts = utils::split(s, " ");
            if (parts.size() > 0) {
                if (parts[0].size() > 0 && parts[0][0] == '-') {
                    std::cout << "\x1B[96m";
                    std::cout << s;
                    std::cout << "\033[0m";
                }
                else {
                    bool codeReached = false;
                    int color = 0;
                    for (std::string part : parts) {
                        if (!codeReached && part.size() == 1) {
                            color = utils::getColorCode(part);
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
        }
    }
    return 0;
}

