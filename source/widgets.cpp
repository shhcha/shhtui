#include "../include/widgets.hpp"

/**
 * @brief core.cpp defines core.hpp
 * 
 */

namespace shhtui::render {
    bool drawText(datatypes::S_Point originPoint, std::string text);
}

namespace shhtui {
namespace widgets {

bool C_SimpleLabel::draw()
{
    render::drawText(_originPoint, _text);
    return true;
}

    
}
}