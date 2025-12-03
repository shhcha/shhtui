// src/app.cpp
#include "../include/app.hpp"
#include "../include/util.hpp"
#include <vector>

namespace shhtui::app {

class C_WindowElement {
public:
    C_WindowElement();
    ~C_WindowElement();



};

class C_AppWindow {
private:
    C_AppWindow();
    ~C_AppWindow();

    std::vector<C_WindowElement> _WindowElementVec; 

public:
    bool addElement(C_WindowElement newElement) {
        _WindowElementVec.push_back(newElement);
        return 1;
    }
    // Returns a vector of C_WindowElements 
    // Input 'index = -1'
    std::vector<C_WindowElement> getElement(const int index = -1)
    {
        std::vector<C_WindowElement> elements;
        if (index == -1)    elements = _WindowElementVec;
        else                elements.push_back(_WindowElementVec.at(index));
        return elements;
    }

};


} // namespace shhtui::renderer
