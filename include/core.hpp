#pragma once

/**
 * @brief core.hpp declares many globals and `C_AppCore`, which handles all major app functionality
 * 
 */

#include "view.hpp"
namespace shhtui {
namespace core
{
    class C_AppCore {
    public:
        /// De/Constructors
        C_AppCore() 
        : _isRunning(true) {};
        ~C_AppCore() {};

        /// Methods
        bool run();

        bool draw();

        bool update();

        bool pollInput();

        bool handleRawByte(char b);

        bool onKeyEvent(const datatypes::S_KeyEvent& ev);

        bool setView(std::shared_ptr<core::C_View> newView);
        


        /// Variables
        bool _isRunning = false;
        std::shared_ptr<core::C_View> _activeView;
    };
}
}