#pragma once

#include <cstdlib>
#include <string>
#include <termios.h>

/**
 * @brief utilities.hpp declares important startup, shutdown, and datatypes
 * 
 */


namespace shhtui {
namespace datatypes {

    struct S_Point {
        int _row = 0;
        int _column = 0;
    };

    struct S_Dimension {
        int _rows = 0;
        int _columns = 0;
    };

    struct S_ColorRgb {
        int _r = 0;
        int _g = 0;
        int _b = 0;
    };

    struct S_TextStyle {
        bool _legacy = false;

        bool _isBold = false;
        bool _isUnderlined = false;

        S_ColorRgb _foregroundColor;
        S_ColorRgb _backgroundColor;

        int _foregroundFallback = 0;
        int _backgroundFallback = 0;

        std::string toAnsiCode() const;
        
    };

} /// ::datatypes

namespace utilities {

    /// Methods

    bool startupTUI();
    bool shutdownTUI();

    bool enableRawTerminal();
    bool disableRawTerminal();

    bool toggleCursorVisibility();
    
    bool moveCursor(datatypes::S_Point toPosition);

    /// Variables
    extern struct termios _originalTerminal;
    extern struct termios _rawTerminal;

    extern bool _isRaw;
    extern bool _isCursorVisible;

} /// ::utilities
}