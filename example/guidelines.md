# SHHTUI-Library: Developer Guidelines

Welcome! This document outlines the fundamental principles and standards for contributing to the TUI-Library project.

---

## 1. Core Architecture Principles

* **Abstraction is Key:** All interaction with the terminal (raw input, cursor movement, color codes) must be encapsulated deep within the library's core. End-users (developers using the library) should only interact with high-level objects
* **Decoupling:** Use design patterns (like **Observer** and **Command**) to keep the UI components (Widgets) separate from the Input Processing logic.
* **Ownership:** Use `std::shared_ptr` for managing component hierarchy (`_children`) and external resources. Use raw pointers (`_parent`) to avoid circular dependencies.

---

## 2. Coding Style Guidelines (C++ Specific)

### 2.1 File Naming & Structure

| Element | Naming Convention | Example |
| :--- | :--- | :--- |
| **Header File (.hpp)** | camelCase | `window.hpp`, `appManager.hpp` |
| **Source File (.cpp)** | camelCase | `window.cpp`, `appManager.cpp` |
| **Structure Names** | PascalCase, prefixed with `C_`, or `S_`, etc. | `class C_Button`, `struct S_InputProcessor` |
| **Function/Method Names** | camelCase | `handleInput()`, `getName()` |
| **Member Variables** | camelCase, prefixed with underscore | `std::string _name`, `int _totalCount` |
| **Constants/Enums** | SCREAMING_SNAKE_CASE | `COLOR_RED`, `KEY_ARROW_UP` |

### 2.2 Includes and Dependencies

* **Header (.hpp) Files:**
    * Use `#pragma once` for include guards.
    * Use **Forward Declarations** (`class MyClass;`) whenever possible to minimize compilation time. Only `#include` headers if absolutely necessary (e.g., for base class inheritance).
* **Source (.cpp) Files:**
    * The corresponding `.hpp` file **must** be the first include.
    * Include all necessary headers here (`<vector>`, `"KeyEvent.hpp"`, etc.).

### 2.3 Memory Management

* Prefer `std::unique_ptr` for exclusive ownership and `std::shared_ptr` for shared ownership (e.g., UI component children).
* Avoid naked `new` and `delete`. Use `std::make_shared` or `std::make_unique`.
* Always define a **virtual destructor** for base classes intended for inheritance (`virtual ~Component() = default;`).

---

## 3. Documentation

* All public classes, methods, and non-trivial member variables must be documented using **Doxygen style comments** (`/** ... */`).
* Example:
    ```cpp
    /**
     * @brief Renders the component to the specified canvas area.
     * @param canvas The drawing surface reference.
     */
    virtual void draw(TUI::Canvas& canvas) const = 0;
    ```