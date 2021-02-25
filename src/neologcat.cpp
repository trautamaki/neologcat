#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "reader.h"
#include "utils.h"

int main(int argc, char **argv) {
    int wantedColor = -1;

    // Handle arguments
    if (argc > 1) {
        wantedColor = utils::stringToMsgType(argv[1][0]);
    }

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
                    // 5th element is the type
                    if (wantedColor != -1 && utils::stringToMsgType(parts.at(4).at(0))
                            != wantedColor) {
                        continue;
                    }

                    bool codeReached = false;
                    int color = 0;
                    for (std::string part : parts) {
                        if (!codeReached && part.size() == 1) {
                            color = utils::getColorCode(part.at(0));
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

