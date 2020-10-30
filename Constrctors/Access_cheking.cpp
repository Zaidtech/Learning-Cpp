// Tries to change the attributes of an obj from the diff class objs..

#include <iostream>
using namespace std;
#include  <string.h>

class Class1{
    private:
        int percentage;
    public:
        string name;
        int roll;
    // Class1(): name("Zaid"), roll(12){
    // } // is this a constructor ? 
};

class Class2{
// make sure this is an external method not a part of class say class2
// making a student by default names Zaid 
public:
void Alter(Class1 student)
    {
        student.name = "Ali";
        student.roll = 12;
    }
}; 

int main()
{
    Class1 student1;
    Class2 student2;
    student2.Alter(student1);
    cout << "Name of the first student is "<< student1.name << "\n";
    cout << "Roll no of the student is "<< student1.roll << "\n";
}         