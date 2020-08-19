#include <iostream>
#include <iomanip>
using namespace std;

int  main(){

    int input ;
    cout << "Enter a number:";
    cin >> input;
    for(int i=1;i<=20;i++){
        for (int j=1;j<=10;j++){
            cout <<setw(6)<< input*(j+i);
        }
        cout << "\n"; 
    }
}
    

