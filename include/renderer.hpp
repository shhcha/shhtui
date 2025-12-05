// renderer.hpp
#ifndef SHHTUI_RENDERER_HPP
#define SHHTUI_RENDERER_HPP

#include "util.hpp"

#include <iostream>
#include <string>

namespace shhtui::renderer {
    
    extern std::string _TextPrefix;
    extern std::string _TextSuffix;

    bool startup();
    bool shutdown();

    bool clearScreen();
    bool refreshScreen();

    bool _drawRawText(std::string msg, std::tuple<int,int> position);
    bool _drawBox(std::tuple<int,int> position, std::tuple<int,int> size, std::string color = std::string(""));

    std::string _formatText(std::string text, std::string prefix = _TextPrefix, std::string suffix = _TextSuffix);


}

#endif