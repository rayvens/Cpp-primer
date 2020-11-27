#pragma once
#include "Screen.hpp"
#include <vector>
class Window_mgr{
    private:
        std::vector<Screen> screens{ Screen(24, 80, ' ') }; //default: window_mgr has one standart sie blank screen


};