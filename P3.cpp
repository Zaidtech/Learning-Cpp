//  Gweting Inputs using "cin" 

#include <iostream>
using namespace std;

int main(){
    int temF;
    cout << "Enter temp in F: ";
    cin >>  temF;  // cin spoken as C in takes input from the stabndard input stream
    //  The >> is the "get from" operator
    int tempC = (temF-32) * 5 / 9;
    cout << "Equivalent temp in Celcius is: " << tempC << " C\n";  
    return 0;
}

//  In C++ constants can be defined usinf preprcessor #define

#define PI = 3.14159 // but the #define is superceded by the "const" keyword

/* Manipulators are the operators used with << and >> to manipulate the displayed data.... For eg.
- endl
- setw
*/
