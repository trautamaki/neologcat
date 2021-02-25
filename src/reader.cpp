#include <stdexcept>
#include "reader.h"
#include <iostream>
reader::reader(const char* cmd) {
    system("adb logcat -c");
    #ifdef _WIN32
    pipe = _popen(cmd, "r");
    #else
    pipe = popen(cmd, "r");
    #endif
    if (!pipe) throw std::runtime_error("Opening adb failed!");
}

reader::~reader() {
    #ifdef _WIN32
    _pclose(pipe);
    #else
    pclose(pipe);
    #endif
}

std::string reader::readLine() {
    std::string r = "";
    while (char c = fgetc(pipe)) {
        r += c;
        if (c == '\n')
            break;
    }
    return r;
}