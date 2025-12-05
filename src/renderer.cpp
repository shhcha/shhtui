// renderer.cpp
#include "../include/renderer.hpp"
#include <memory>

namespace shhtui::renderer {
   
std::string _ColorPrefix = std::string("\033[31;1;4m");
std::string _ColorSuffix = std::string("\033[0m");

// Enables Raw Mode
bool startup() {
    std::cout << "\033[?25l"; // Hide Cursor
    return 1;
}

// Disables Raw Mode
bool shutdown() {
    std::cout << "\033[?25h";
    std::fflush(stdout);
    return 1;
}

// Clears Terminal Output, call 'renderer::refreshScreen()'
bool clearScreen() {
    std::cout << "\x1B[2J\x1B[H";    return 1;
}

bool refreshScreen() {
    std::cout << std::flush;
    return 1;
}

bool _drawRawText(std::string msg, std::tuple<int,int> position) {

    util::_moveCursor({
        std::get<0>(position), // r
        std::get<1>(position)} // c
    );
    std::cout << msg;

    return 1;
}

bool _drawBox(std::tuple<int,int> position, std::tuple<int,int> size, std::string color) {
    
    int r  = std::get<0>(position);
    int c  = std::get<1>(position);

    int w = std::get<1>(size); // Width is columns
    int h = std::get<0>(size); // Height is rows

    
    if (!color.empty()) {
        _ColorPrefix = color;
    } else {
        _ColorPrefix = ""; // or keep default
    }

    std::string boxElementHorizontal = _formatText("─", _ColorPrefix, _ColorSuffix); // top/bottom sides
    std::string boxElementVertical   = _formatText("│", _ColorPrefix, _ColorSuffix); // left/right sides
    std::string boxElementTopLeft    = _formatText("┌", _ColorPrefix, _ColorSuffix);
    std::string boxElementTopRight   = _formatText("┐", _ColorPrefix, _ColorSuffix);
    std::string boxElementBottomLeft = _formatText("└", _ColorPrefix, _ColorSuffix);
    std::string boxElementBottomRight= _formatText("┘", _ColorPrefix, _ColorSuffix);


    // 1️⃣ Top border
    _drawRawText(boxElementTopLeft, {r, c});                  // top-left corner
    for (int col = 1; col < w - 1; col++)                     // horizontal line
        _drawRawText(boxElementHorizontal, {r, c + col});
    _drawRawText(boxElementTopRight, {r, c + w - 1});        // top-right corner

    // 2️⃣ Left & Right sides
    for (int row = 1; row < h - 1; row++) {
        _drawRawText(boxElementVertical, {r + row, c});       // left side
        _drawRawText(boxElementVertical, {r + row, c + w - 1}); // right side
    }

    // 3️⃣ Bottom border
    _drawRawText(boxElementBottomLeft, {r + h - 1, c});       // bottom-left corner
    for (int col = 1; col < w - 1; col++)                     // horizontal line
        _drawRawText(boxElementHorizontal, {r + h - 1, c + col});
    _drawRawText(boxElementBottomRight, {r + h - 1, c + w - 1}); // bottom-right corner
    
    return 1;
}

std::string _formatText(std::string text, std::string prefix, std::string suffix)
{
    if (!(prefix.empty() || suffix.empty()))
    {
        _ColorPrefix = prefix;
        _ColorSuffix = suffix;
    }
       
    return std::string(prefix + text + suffix);
}


}

