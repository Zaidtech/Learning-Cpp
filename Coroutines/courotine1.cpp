// Courotines are the general control statements where flow is cooperatrively passsed btw two diff routines
// yeild keyword in Python is an example 
// ie the concept of remembering the state is mentioned
//  C itself is a stacked based language .

#include <iostream>
using namespace std;

// the aim is to remember the previous state and continue the left execution
int read(){
    int i;
    for(i =0; i<10;i++){
        return i;
    }
}
// To remember the state we will use the Duff's device ..
//  in the next C code