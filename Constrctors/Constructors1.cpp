#include <iostream>
using namespace std;

class Rectangle{
    private:
        int width;
        int length;
    public:
        Rectangle(); // default constructor 
        Rectangle(int w, int l);  // parameterized constructor
        Rectangle(const Rectangle& ); // copy constructor
        void set(int w, int l);
        int area();
};

Rectangle::Rectangle(){
    //this is an eg, of a defalut  constructos.
    cout << "This is the default constructor overloading...";
}

Rectangle::Rectangle( int w , int l)
{
    this->length = l;
    this->width  = w;    
}

int main(){
    Rectangle r1; // default const.    
    Rectangle r2(10,20); //
    Rectangle r3 = r2;
    cout << r3;
}