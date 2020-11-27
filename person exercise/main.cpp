#include <iostream>

struct person{
    //constructors
    friend std::ostream& print(std::ostream&, const person&);
    friend std::istream& read(std::istream&, person&);
    public:
    person(): name("NoName"), address("NoAddress") {} 
    person(const std::string& n, const std::string& a): name(n), address(a) {}
    //members    
    std::string getname() const { return name; }
    std::string getaddress() const { return address; }
    private:
    std::string name;
    std::string address;
};

std::ostream &print(std::ostream& os, const person& person1){
    os << person1.getname() << " " << person1.getaddress();
    return os;

};
std::istream &read(std::istream& is, person& person1){
    is >> person1.name >> person1.address;
    return is;
};

int main(){
    person alm;
 read(std::cin,alm);
 print(std::cout,alm);
}