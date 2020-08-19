//  Alter Values
#include <iostream>
using namespace std;

int alter(int no1,int no2){
    no1 +=10;
    // no2 +=10;
    // cout << no2;
    return no1;
}

int main(){
    int a,b;
    cout << "Enter two numbers: "; cin >> a,b;
    cout << 'no1 is ' << a << endl<< "no2 is "<< b<< endl;
    alter(a,b);
    cout << 'no1 is ' << a << endl<< "no2 is "<< b<< endl;
    // cout << a << endl;
}