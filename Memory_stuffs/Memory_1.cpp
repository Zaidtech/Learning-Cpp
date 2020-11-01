#include <iostream>
#include <stdio.h>
using namespace std;
// some global var

int number = 10;
// this whole function will be in the stack
tore 
class Sum {
    public:
    int long long summation = 0;        
};


int some_function(int a ,int b){
    // Some local vars of the function in the stack 
    sum.summation = 0;
    if (sum.summation >1000000000) return 0;
    sum.summation = a+b+number;
    return sum.summation;
}
//  will be in the stack as well

int main(){

    Sum sum = new Sum();
    int long long large = 210;
    int a=0;
    int b=0;
    a = 200;
    b = 100;
    int i = 0;
    for (;i<some_function(a,b);)
        cout << some_function(a,b);
}



