// include/renderer.hpp
#pragma once

#include <tuple>
#include <string>

namespace shhtui {

    namespace renderer {
        
        bool start();

        // Basics
        bool clearConsole();

        bool _drawRawText(std::tuple<int, int> position, std::string message);

    }

} // namespace shhtui