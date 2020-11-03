//  The case of static vars in a class is a unique one
// Firstly it requires a diff way of declaration 
//  Defined in a class and declared outside
// If they would have been in the class it was voilating the definition of Class as it was asiding a memory

#include <iostream>
#include <string>
using namespace std;

class Student{

public:
    string name;
    static int rolno; // decalring a static var , no memery allocation is done yet
    char i;

    void display()
    {
        cout << name << " " << rolno <<endl;
    }
};

// Defining the static vars
int Student::rolno = 12;

int main(){


    Student *stud1 = new Student;
    Student stud2;
    // there are two methods of initiazing an obj, what makes the diff ?? 
    // 
// 1.
    stud1->name = "Zaid";
    stud1->rolno=12;
    stud1->display();
// 2. 
    stud2.name = "Ali";
    stud2.rolno = 23;
    stud2.display();        
    stud1->display();

}

