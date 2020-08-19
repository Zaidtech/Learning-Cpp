#include <iostream>
using namespace std;

int a=20;
int b ;

int alter(int a,int b)
{
    ::a = a+10;
    ::b = ::b+10;
    cout << "a is "<< a << endl;
    cout << "b is "<< ::b << endl;  
    return 0;
}

int main()
{
    alter(::a,::b);
    cout << "a is "<< ::a<< endl;
    cout << "b is "<< b<< endl;
}
