#pragma once

#include <string>

/**
 * @brief widgets.hpp declares ALL first party widgets, and the `S_WidgetParent` struct
 * 
 */

#include "utilities.hpp"

namespace shhtui {
namespace widgets {

    struct S_WidgetStruct
    {
        /// De/Constructor
        S_WidgetStruct(
            datatypes::S_Point originPoint,
            datatypes::S_Dimension maxSize,
            std::string id
        ) :
            _originPoint(originPoint),
            _maxSize(maxSize),
            _id(id) {};
        ~S_WidgetStruct() {};

        /// Methods

        virtual bool draw() { return false;};
        virtual bool handleInput() { return false;};
        virtual bool update() { return false;};

        /// Variables
        datatypes::S_Point _originPoint;
        datatypes::S_Dimension _maxSize;
        std::string _id;
    };

    class C_SimpleLabel: public S_WidgetStruct
    {
    public:
        /// De/Constructor
        C_SimpleLabel(
            datatypes::S_Point originPoint,
            datatypes::S_Dimension maxSize,
            std::string id,
            std::string message
        ) :
            S_WidgetStruct(originPoint,maxSize,id),
            _text(message) {};
        ~C_SimpleLabel() = default;

        /// Methods

        bool draw() override;

        /// Variables
        std::string _text;

    };

}
}