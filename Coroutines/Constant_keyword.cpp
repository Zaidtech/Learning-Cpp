//  A method declared as constant will never modify its class members 

#include <iostream>
using namespace std;

class Class{
private:
  int marks;

public:
    // some methods 
    // the display methos is the best eg of a const method
    void display() const {
            cout << "Marks are : "<< marks<< endl;
    }

    void teacher_grace()  {
            marks = 10;
    }

};

int main(){
    Class s;
    s.display();  
}