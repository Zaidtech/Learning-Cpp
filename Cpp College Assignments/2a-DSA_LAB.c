//  Lab 2 (a) Sort-Bubble
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_sorted(int [], int, int);
void Standard_sort(int [], int);
void Early_term_sort(int [], int);
void Cocktail_sort(int [], int);

int  main(){
    int N=0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &N);
    int Array1[N];
    int Array2[N];
    int Array3[N];
    srand(time(0));   // seeding rand with the current time
    for(int i=0;i<N;i++){
        Array1[i] = Array2[i] = Array3[i] = (rand()%100);
        printf("%d ,", Array1[i]);
    }
    printf("\b\b\n");
    // Calling functions 
    Standard_sort(Array1, N);
    Early_term_sort(Array2, N);
    Cocktail_sort(Array3, N);

}

void Standard_sort(int Array[], int N){
    printf("Sorting array using Standard Bubble sort...\n ");
    for(int i=N-1;i>0;i--){
        int cmp =0;
        for(int j=0;j<i;j++){
            int temp =0;
            if(Array[j+1] < Array[j])
            {
                temp = Array[j+1];
                Array[j+1] = Array[j];
                Array[j] = temp;
            }
            cmp ++;
        }
        display_sorted(Array,cmp, N);  
    }
    printf("\n");
}   

void Early_term_sort(int B[], int N){
    printf("Sorting using early termination method...\n");
        for(int i=N-1;i>0;i--){
        int cmp =0;
        int is_comp_done = 0;
        //  needed to used int instead of the bool cause identifier not defined error...
        for(int j=0;j<i;j++){
            int temp =0;
            if(B[j+1] < B[j])
            {   
                is_comp_done ++;
                temp = B[j+1];
                B[j+1] = B[j];
                B[j] = temp;
            }
            cmp ++;    
        }
        display_sorted(B, cmp, N);
        if(is_comp_done == 0)
                break;    
    }
    printf("\n \n");
}

void Cocktail_sort(int Array[], int N){
    printf("Sorting using Cocktail Algo..\n ");
    int end = N-1;
    int start =0;
    int swap =1;
    while(swap==1){
                swap =0;     
                int cmp = 0;
            // Strating from staring ... 0 1 2 3 ...
                printf("Sorting from starting  : ");
                for(int j=start; j< end ;j++){     
                if(Array[j] > Array[j+1])
                {   
                    int temp = 0;
                    temp = Array[j+1];
                    Array[j+1] = Array[j];
                    Array[j] = temp;
                    swap =1;
                }
                cmp ++;
                // if(swap==0)break;
                //since nothing is swaped all are sorted
            }   
                display_sorted(Array, cmp, N);
                --end;  
                cmp =0;
                if(swap ==0) break;
                printf("Sorting from last      : ") ;  
            for(int j=end-1; j>=start;j--)
            {
            if(Array[j] > Array[j+1])
                {   
                int temp = 0;
                temp = Array[j+1];
                Array[j+1] = Array[j];
                Array[j] = temp;
                }
            cmp ++;
            }
           
            ++start;
            display_sorted(Array, cmp, N);
            
        }
    }

void display_sorted(int A[], int cmp, int N){
    for(int i=0; i<N;i++){
        printf("%d ", A[i]);
        
    }
    printf("Comparisons Done %d \n ", cmp);
}
