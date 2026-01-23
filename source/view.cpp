#include "../include/view.hpp"

/**
 * @brief view.cpp defines view.hpp
 * 
 */

namespace shhtui {
namespace core {

bool C_View::addWidget(std::shared_ptr<widgets::S_WidgetStruct> newWidget)
{
    if (!newWidget) return false;
    _widgets.push_back(newWidget);
    return true;
}

bool C_View::draw()
{
    for (int i = 0;i<_widgets.size();++i)
    {
        auto w = _widgets[i];
        w->draw();
    }
    return true;
}

bool C_View::handleInput(const datatypes::S_KeyEvent& ev)
{
    
    return true;
}

}
}