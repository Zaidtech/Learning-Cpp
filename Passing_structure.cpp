#include <iostream>
using namespace std;


struct Distance{

int feet;
int inches;

};

void engDisplay( Distance );


int main(){
    Distance d1, d2;
    // Taaking some inputs...
    engDisplay(d1);
    engDisplay(d2);
        
}

void engDisplay(Distance d){
    cout << d.feet<<" \' "<< d.inches<<endl;
}

