#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int stack_overflow(int n){
    // all the stack stuff
    int sum=0;
    if(sum==100)
        return sum;
    sum+=n;
    stack_overflow(sum);

    // now the heap stuff the pool of memory

    // make an integer pointer
    // what the above line does it is it occupies 4bytes*1000 ie 4000 bytes from my ram for free use

}

int main(){
    // stack_overflow(20);
    //without any terminating condition this will be making lots of stack frames
    // every time a stack frame is created the stack pointer moves woth it
    //  A stack pointer is a register that holds the requests of the last program request in the frame
    // if not termiantoin then the stack pointer will cross the bound and overflow occurs like that water flowing from a glass 
    // to get size of stack use "ulimit -a" in the terminal for linux.
     
     int long long  *ptr = new int long long[100000000];char q;
     cout << "press key q to free meemry";
     cin >> q;
    free(ptr); 
}

// void something_on_heap(){

// }