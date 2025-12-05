// shhtui.cpp
#include "../include/shhtui.hpp"
#include <cstdlib>
#include <termios.h>
#include <unistd.h>

namespace shhtui::core {

static termios _originalTermios;
static termios _rawTermios;

bool startup() {
    if (tcgetattr(STDIN_FILENO,&_originalTermios) == -1) {
        return false;
    }
    
    _rawTermios = _originalTermios;
    _rawTermios.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    _rawTermios.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    _rawTermios.c_oflag &= ~(OPOST);
    _rawTermios.c_cflag |= (CS8);

    _rawTermios.c_cc[VMIN] = 0;
    _rawTermios.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &_rawTermios) == -1)
            return 0;
    renderer::startup();
    renderer::clearScreen();
    return 1;
}

bool shutdown() {
    renderer::clearScreen();
    renderer::shutdown();
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &_originalTermios);
    return 1;
}

}
