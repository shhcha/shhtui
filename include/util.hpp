// include/util.hpp
#pragma once

#include <termios.h>
#include <tuple>

namespace shhtui {

    namespace util {
        bool start();

        bool _enableRaw();
        bool _disableRaw();

        bool enableCursor();
        bool disableCursor();

        bool moveCursor(std::tuple<int,int> cursorPos);

    } // namespace util

} // namespace shhtui