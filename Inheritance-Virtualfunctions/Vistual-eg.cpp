#include <iostream>
using namespace std;

class Base{
public:
    virtual void print(){
        cout << "printing the base class"<<endl;
    }
    void show(){
        cout << " show base class"<<endl;
    }

};

class Derived: public Base{
    void print(){
        cout << "Printing the derived one";
    
    }
    void show(){
        cout << "Showing the derived one";
    }
};


int main(){
    Base *bptr;//initializing a base obj pointer... it means an obj bptr that points to an obj of class Base
    Derived d;//making an obj of class base
    bptr = &d;
    bptr->print();
    bptr->show();
}