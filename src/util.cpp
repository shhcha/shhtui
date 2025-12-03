// src/util.cpp
#include "../include/util.hpp"

#include <termios.h>
#include <iostream>
#include <unistd.h>
#include <cstdio>

namespace shhtui::util {

static termios origTermios;
static bool rawEnabled = false;

bool start() {
    if (tcgetattr(STDIN_FILENO, &origTermios) == -1) {
        return false;
    }
    return disableCursor() && _enableRaw();
}

bool _enableRaw() {
    if (rawEnabled) return true;

    termios raw = origTermios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);

    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
        return false;

    rawEnabled = true;
    return true;
}

bool _disableRaw() {
    if (!rawEnabled) return true;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &origTermios) == -1)
        return false;

    rawEnabled = false;
    return true;
}

bool enableCursor() {
    // ANSI escape to show cursor
    std::printf("\033[?25h");
    std::fflush(stdout);
    return true;
}

bool disableCursor() {
    // ANSI escape to hide cursor
    std::printf("\033[?25l");
    std::fflush(stdout);
    return true;
}

bool moveCursor(std::tuple<int,int> cursorPos) {
    std::cout << "\033[" << std::get<0>(cursorPos) << ";" << std::get<1>(cursorPos) << "H";
    return true;
}

} // namespace shhtui::util
