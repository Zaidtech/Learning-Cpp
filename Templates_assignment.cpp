#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
T avg(T Array, int n){
    T average ; 
    for(int i=0;i<n;i++){
        averag +=Array[i]
    }
    return (avgerage/n);
}

int  main(){
    int n = 0;
    cout << "Enter the no of elements to be generated in the array: ";
    cin >> n;
    // making an integer array
    int Array[n];
    
    srand(time(0));
    for(int i=0;i<n;i++){
        Array[i] = rand()%100;
    }
    
    avg<int>(Array,n);
    // some char array
    // function call

    // some double array
    // function call

}