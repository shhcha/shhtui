#include "../include/core.hpp"

/**
 * @brief core.cpp defines core.hpp
 * 
 */

namespace shhtui {
namespace core {

bool C_AppCore::run()
{ 
    handleInput();
    update();
    draw();
    return true;
};

bool C_AppCore::draw()
{
    if(!_activeView) {return false;};
    _activeView->draw();
    return true;

}

bool C_AppCore::update()
{
    // if(!_activeView) {return false;};
    // _activeView->update();
    return true;

}

bool C_AppCore::handleInput()
{

    // if(!_activeView) {return false;};
    // _activeView->handleInput();
    return true;

}

bool C_AppCore::setView(std::shared_ptr<core::C_View> newView)
{
    _activeView = newView;
    return true;
}
    
}
}