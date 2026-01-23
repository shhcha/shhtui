#pragma once

#include "widgets.hpp"
#include <memory>
#include <vector>
#include <string>

/**
 * @brief view.hpp declares main viewport class
 * 
 */


namespace shhtui {
namespace core {
    class C_View {
    public:
        /// De/Constructors
        C_View(std::string name) {};
        ~C_View() {};

        /// Methods
        bool addWidget(std::shared_ptr<widgets::S_WidgetStruct> newWidget);
        bool draw();
        bool handleInput(const datatypes::S_KeyEvent& ev);

        /// Variables
        std::string _id;
        std::vector<std::shared_ptr<widgets::S_WidgetStruct>> _widgets;
    };
}
}