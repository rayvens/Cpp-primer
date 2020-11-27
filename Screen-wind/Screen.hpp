#pragma once
#include <iostream>
//screen class represent a windows on a display
//each screen has a string member that hold the content and string::size_type to hold
// position of the cursor, height and width of the screen

class Screen{
    public:
        typedef std::string::size_type pos;
        Screen() = default; // needed to initialized cursor to 0
        Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd,c) { }
        Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd,' ') { }

        //display overloeaded on whether the object is const or not
        Screen& display(std::ostream& os) 
         { do_display(os); std::cout<<"\nnonconst func\n"; return *this; }
        const Screen& display(std::ostream& os) const 
         { do_display(os); std::cout<<"\nconst func\n";return *this; }
        Screen& set(char);
        Screen& set(pos, pos, char);
        char get() const {return contents[cursor]; } //implicit inline
        inline char get(pos ht, pos wd) const; // explicit inline
        Screen& move(pos r, pos c); // can be made inline later
        void some_member() const;
    private:
        mutable size_t access_ctr; //may change even in a const object/function
        pos cursor = 0;
        pos height = 0;
        pos width = 0;
        std::string contents;
        void do_display(std::ostream& os) const { os << contents; }
};

void Screen::some_member() const {
    ++access_ctr; // will change on const because its muttable
}

inline Screen& Screen::move(pos r, pos c){
    pos row = r * width; //compute row location
    cursor = row + c; //move cursor to the column with that row
    return *this;
}

char Screen::get(pos r, pos c) const { //declare inline in the class
    pos row = r* width; //compute row location
    return contents[row + c]; // return character at given column
}

inline Screen& Screen::set(char c){
    contents[cursor] = c; //set new value at current cursor location
    return *this; //return object as lvalue
}

inline Screen& Screen::set(pos r, pos col, char ch){
    contents[r * width + col] = ch; //set specified location to given value
    return *this;
}
