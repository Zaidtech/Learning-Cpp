#include <iostream>
using namespace std; 
// temmapltes

template <typename T>
T myMax(T x, T y){
    return (x>y)?x:y;
}

int main(){
std::cout << myMax<int>(3,7) << endl;
std::cout << myMax<int>('g','h');
}