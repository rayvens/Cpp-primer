#include <iostream>
#include "Screen.hpp"

int main(){
    
    Screen myscreen;
    char ch = myscreen.get(); //call screen::get()
    ch = myscreen.get(0,0);   //call screen::get(pos, pos)
    Screen test(5,6,'X');
    ch = test.move(3,5).set('#').get();
    char ct = test.get(2,3);

    Screen test2(5,10,'N');
    const Screen test3(5,10,'C');

    test2.set(2,3,'X').display(std::cout);std::cout<<std::endl;
    test3.display(std::cout);
}