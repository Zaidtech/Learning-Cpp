// "setw " a manipulator  example

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    long pop1 = 29329839018, pop2 = 2343, pop3 = 90;
    cout << setw(8)<< "LOCATION"<< setw(12)<< "POPULATION" <<endl ;
    cout << setw(8) << "PortCity" << setw(12) << pop1 << endl;
    cout << setw(8) << "LasVegas" << setw(12) << pop2 << endl;
    return 0;

}

