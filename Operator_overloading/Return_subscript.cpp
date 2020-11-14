#include <iostream>
#include <process.h>
using namespace std;

class safearray{
    private:
        int array[200];
    public:
    // return by reference
        int& operator [](int n){
            if(n<0 || n>=200){
                cout << "Index out of bound"; exit(1); 
            }
            return array[n];
        }
        void display() const{
            for(int i =1;i<200;i++){
                cout << array[i];
            }
        }   
};

int main(){
    safearray s1;
    
    for(int j=0; j<200;j++){
        s1[j] = j*10;
    }
    s1.display();
}   