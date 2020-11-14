#include <iostream>
using namespace std;

template <typename T>
class Array{
private:
    T *ptr; // a pointer var of type T
    int size;
public:
    // making a consructor in cpp
    Array( T arr[], int s);//declaring  a constructor
    void print();
};

template <typename T>
Array<T>::Array(T arr[], int s){
    ptr = new T[s]; // making a new array of type T
    size  = s;
    for(int i =0; i<size;i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print(){
    for(int i=0;i<size;i++){
        cout << " "<< *(ptr+i); 
    }
    cout << endl;
}
