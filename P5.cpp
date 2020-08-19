#include <iostream>
using namespace std;

int main(){
    int intVar = 150000000;
    intVar =   (intVar*100);
    cout << "Value of intVar is :" <<  intVar << endl; // This gives the wrong answer...

    intVar = 150000000; 
    // WE will cast it to a double
    intVar = static_cast<double>(intVar)  ;
    cout << "intVar is now" << intVar << endl;
    cout << "Performing Calculation....." << endl;
    intVar  = (intVar*100)/ 200;
    cout << "intVar is now" << intVar << endl;
}
// Casting may be done using:
// aCharVar = (char)Variable_to_be_changed , however this approach is discouraged , as difficult 
//  to find in seacrch operations





