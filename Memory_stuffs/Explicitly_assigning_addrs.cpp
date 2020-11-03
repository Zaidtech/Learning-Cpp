#include <iostream>
#include <string> 
using namespace std;

int main(){
    // char * data = new char(sizeof(string));
    char *data = new char[100];
    string  *stringPtr = new string("ABCD");
    cout << *stringPtr << " at: "<< stringPtr << endl;

    stringPtr->~basic_string();
    stringPtr = new (data)string("123456");
    cout << *stringPtr<< " at: "<< stringPtr << endl;
    stringPtr->~basic_string();
    delete[] data;
}