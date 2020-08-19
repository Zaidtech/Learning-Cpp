/*
Using SRO to resolve the name conflicts
Defining our own class 
*/


#include <iostream>
using namespace std;

class sample{
     public :
        static int count;

};

int main(){

    int count = 100;
    cout << "Value of the local(count): " << count << endl;
    cout << "Value of the gobal(count) "<< sample::count<< endl;

}

