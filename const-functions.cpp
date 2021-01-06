// there are two things , a const obj... a const function...

#include <iostream>
using namespace std;



class Class1{
private:
    struct {
        int someAttr;
        char name[100];
    };

public:
    void function1() const{
        cout << "A fucking obj";
    }
    void some_funtion(Class1 obj) {
        obj.someAttr = 1;
        obj.name[4] = 'Zaid';
        cout << "A bullshit";
    }

};

int main(){
    Class1 obj1;
    obj1.function1();
    Class1 obj2;
    obj2.some_funtion(obj2);
}