// Some Libraries Examples 
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double answer = 0, number;
    cout << "enter a number ";
    cin >> number;
    cout << "You entered "<< number << endl;
    cout << "Square Root of the number is  "<< sqrt(number) << endl;


}
/* Diff btw. a Library file and a header File...
->Say you want to use a function named sqrt() , then you must link the library file 
containing this function.
->The appropriate functions are then connected to the program using the linker.
->However our source code needs to know about the name and type of the functions and the elements 
in Library file.
->This definition is contined in the Header Files (usually ending with .h).

In short..

functions in a library file and their info is scattered in the headers file , to be acesses through.
 

*/
