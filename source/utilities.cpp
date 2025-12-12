#include "../include/utilities.hpp"

#include <iostream>
#include <unistd.h>
#include <sstream>

/**
 * @brief utilities.cpp defines utilities.hpp
 * 
 */

namespace shhtui::render /// Forward declare
{
    bool clearScreen();
    bool refreshScreen();
}

namespace shhtui {
namespace datatypes {

std::string S_TextStyle::toAnsiCode() const
{
    std::stringstream ss;
    ss << "\033[";

    /// Reset Code
    ss << "0";

    /// Foreground
    if (!_legacy)
    {
        ss  << ";38;2;" << (int)_foregroundColor._r /// Foreground
            << ";" << (int)_foregroundColor._g
            << ";" << (int)_foregroundColor._b;

        ss  << ";48;2;" << (int)_backgroundColor._r /// Background
            << ";" << (int)_backgroundColor._g
            << ";" << (int)_backgroundColor._b;
    } else
    {
        ss << ";" << (30 + _foregroundFallback);
        ss << ";" << (40 + _backgroundFallback);
    }

    /// Attributes
    if (_isBold) ss << ";1";
    if (_isUnderlined) ss << ";4";

    ss << "m";

    return ss.str();
}

} /// ::datatypes

namespace utilities {

bool startupTUI()
{
    enableRawTerminal();
    toggleCursorVisibility();
    render::clearScreen();
    render::refreshScreen();
    return true;
}

bool shutdownTUI()
{

    return true;
}

bool enableRawTerminal()
{
    if (tcgetattr(STDIN_FILENO, &_originalTerminal) == -1) {
        return false;
    }

    _rawTerminal = _originalTerminal;

    _rawTerminal.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    _rawTerminal.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    _rawTerminal.c_oflag &= ~(OPOST);
    _rawTerminal.c_cflag |= (CS8);

    _rawTerminal.c_cc[VMIN] = 0;
    _rawTerminal.c_cc[VTIME] = 0;


    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &_rawTerminal) == -1) {
        return false;
    }
    _isRaw = true;
    return true;
}

bool disableRawTerminal()
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &_originalTerminal) == -1) {
        return false;
    }
    _isRaw = false;
    return true;
}

bool toggleCursorVisibility()
{
    if(_isCursorVisible)
    {   /// Hides Cursor
        std::cout << "\033[?25l";
    }
    else 
    {   /// Shows Cursor
        std::cout << "\033[?25H";
    }
    return true;  
}

bool moveCursor(datatypes::S_Point toPosition)
{
        std::cout <<
    "\033[" << 
    toPosition._row << ';' <<
    toPosition._column << 'H';
    return true;
}

/// Variables

struct termios _originalTerminal = {};
struct termios _rawTerminal = {};

bool _isRaw = false;
bool _isCursorVisible = true;

} /// ::utilities

}