#include "../include/renderer.hpp"

#include <iostream>

/**
 * @brief renderer.cpp defines renderer.hpp
 * 
 */

namespace shhtui::utilities /// Forward Declare
{
    extern bool _isRaw;
}
// namespace shhtui::datatypes
// {
//     struct S_TextStyle {
//         std::string toAnsiCode();
//     };
// }

namespace shhtui {
namespace render {

/// Functional Methods

bool clearScreen()
{
    if(!shhtui::utilities::_isRaw)
    {
        return false;
    }
    std::cout << "\x1B[2J\x1B[H";
    return true;
}

bool refreshScreen()
{
    if(!shhtui::utilities::_isRaw)
    {
        return false;
    }
    std::cout.flush();
    return true;
}

bool pushStyle(datatypes::S_TextStyle &newStyle)
{
    _currentStyle = newStyle;
    _styleStack.push(newStyle);

    std::cout << _currentStyle.toAnsiCode();
    std::cout.flush();

    return true;
}

bool popStyle()
{
    if (_styleStack.empty()) {
            return false;
        }

    _styleStack.pop();
    if (_styleStack.empty()) {
        return true;
    }
    datatypes::S_TextStyle previousStyle = _styleStack.top();
    
    std::cout << previousStyle.toAnsiCode();
    
    _currentStyle = previousStyle;
    
    return true;
}

/// Rendering Methods

bool drawText(datatypes::S_Point originPoint, std::string text)
{
    if (!utilities::moveCursor(originPoint)) {return false;};
    std::cout << text;
    return true;
}

/// Variables

datatypes::S_TextStyle _currentStyle;
std::stack<datatypes::S_TextStyle> _styleStack = {};


}
}