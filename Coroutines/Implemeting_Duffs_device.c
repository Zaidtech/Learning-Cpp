// C code to show how the subroutines can be implemented using Duff's device
// This eg is based on the range function in the python3 which itself is based on the couritine as it return a generator
#include <stdio.h>

int range(int a , int b){
    // use of the keyword static ??
    //  static varioables help in retaining the state btw the diff. function calls
    
    static long long int i;
    static int state =0 ;
    switch(state){
        case 0:
            state =1;
            for(i=a; i<b;i++){

                return i;

                case 1: ;

            }
    }
    state = 0;
    return 0;
}

int main(){
    int i;
    for(; i=range(1,5);)
        printf("Control at the main : %d \n",i);
    return 0;
}