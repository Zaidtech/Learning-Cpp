#include <iostream>
using namespace std;

int func1(); 
int func2(int);

int main(){
    printf(" What does this pos points to about func1 --> %p \n", &func1); // is there any thing like this.. what are function designatorss
    printf(" What does this pos points to about main --> %p \n ", &main);   
    printf("%d", func1());
}

int func1(){
    int value = 10;
    int A[10000000];
    for(int i=0; i<1000000000;i++){
        A[i] = i+10;
    }
    printf("%p \n", &value);
    printf("%d \n", func2(value));
    printf("%p \n", func2);
    printf("%p \n", main);
    return func2(value);

}

int func2(int value){
    int sum = 0;
    return (sum+value);
}

