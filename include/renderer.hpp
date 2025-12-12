#pragma once

#include "utilities.hpp"
#include <stack>
#include <string>

/**
 * @brief renderer.hpp declares ALL rendering functionality
 * 
 */

namespace shhtui::datatypes 
{
    struct S_TextStyle;
    struct S_Point;
}
namespace shhtui::utilities
{
    bool moveCursor(datatypes::S_Point toPosition);
}

namespace shhtui {
namespace render {

    /// Funtional Methods

    bool clearScreen();
    bool refreshScreen();

    bool pushStyle(datatypes::S_TextStyle &newStyle);
    bool popStyle();

    /// Rendering Methods

    bool drawText(datatypes::S_Point originPoint, std::string text);

    extern datatypes::S_TextStyle _currentStyle;
    extern std::stack<datatypes::S_TextStyle> _styleStack;
}
}