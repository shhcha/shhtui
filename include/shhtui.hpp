// shhtui.hpp
#ifndef SHHTUI_HPP
#define SHHTUI_HPP

#include "app.hpp"
#include "renderer.hpp"
#include "util.hpp"

#include <termios.h>

namespace shhtui {

    namespace core {
        bool startup();
        bool shutdown();
    }

    extern const char* version();

}

#endif