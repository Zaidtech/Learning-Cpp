#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int [], int);
void merge(int L[], int sizeL , int R[], int sizeR, int A[]);

int  main(){
    int num =0;
    printf("Enter number of terms to be generated: ");
    scanf("%d", &num);
    int Array[num];
    srand(time(0));
    for(int i=0; i<num;i++){
        Array[i] = (rand()%100) ;
    }
    printf("Random array generated of length %d is : ",num);
    for(int i=0; i<num;i++){
        printf("%d,",Array[i]); 
    }
    printf("\b \b \n");
    merge_sort(Array, num);
}

void merge_sort(int A[],int num){
    int n =0;
    n = num;
    int mid =0;
    if(n%2==0){
        mid = n/2;
    }
    else{
        mid = n/2 +1;
    }
    int Left[n/2];
    int Right[n-mid];

    if(n <2){
    //  printf("RECHECD END OF THIS CALL");
     return;
    }    
    // Filling the Left and the right arrays..

    for(int i=0;i<mid;i++){
        // printf("Filling left array \n");
        Left[i] = A[i];
    }
    
    for(int i=mid ;i< n;i++){
        // printf("Filling right array \n");
        Right[i-mid] = A[i];
    }
        // Displaying the arrays

    // printf("Displaying the left array of size %d : ", mid);
    for(int i=0 ;i<mid;i++){
        printf("%d ", Left[i]);
    }
    printf(" | ");

    // printf("Displaying the Right array of size %d : ", n-mid);
    for(int i=0;i< n-mid;i++){
        printf("%d ", Right[i]);
    }
    printf("\n");

    // printf("Calling left sort \n ");
    merge_sort(Left, mid);
    // printf("Called right sort \n ");    
    merge_sort(Right, n-mid);
    // printf("Called merge function \n "); 

    merge(Left, mid, Right, n-mid, A);

    // printf("Does it ever reaches here \n");
}


void merge(int L[], int sizeL , int R[], int sizeR, int A[]){

    int nL = sizeL;
    // int L[nL];
    int nR = sizeR;
    // int R[nR];
    int i = 0;
    int j=0; 
    int k=0;
    int u =0;

    if(u >0){
        
        printf("Performing the merge of above pair now");
    }
    else{
         printf("\n Performing Merging... \n ");
    }
    u++;

    printf("No of elements in left and right arrays are %d %d \n ", nL, nR);

    
    while(i <nL && j<nR){
        if( L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
        while(i < nL){
            A[k] = L[i];
            k++;
            i++;
        }
        while(j<nR){
            A[k] = R[j];
            j++;
            k++;
        }

    printf("After merging : ");
    // printf("Left array is : ");
    for(int i=0; i<k;i++){
        printf("%d ", A[i]);
    }
    printf("\n \n");
}