#include <stdexcept>
#include "reader.h"
#include <iostream>
reader::reader(const char* cmd) {
    system("adb logcat -c");
    pipe = _popen(cmd, "r");
    if (!pipe) throw std::runtime_error("Opening adb failed!");
}

reader::~reader() {
    _pclose(pipe);
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