#include <stdio.h>

void display(int Array[], int N){
    for(int i =0;i<N; i++){
        Array[i] = Array[i]+10;
    }
}
int main(){
    int Array[] = {1,3,4,5,6,6};
    int n = 6;
    display(Array, n);
    for(int i = 0; i<n;i++){
        printf("%d \n", Array[i]);
    }
}
