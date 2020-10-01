// Factorial function
#include <iostream>
using namespace std;

int fact(unsigned int long long ,unsigned int long long);

int main(){
    int n=0;
    int f=1;
    cin >> n;
    cout << "Factorial of the number : " << fact(n,f);   
}

int fact(unsigned int long long no, unsigned int long long f){
    f = f*no;
    
    if(no==1)
    return f;
    fact(--no,f);
    
}

