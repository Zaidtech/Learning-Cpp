// DSA LAB -- 1(a)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linear_search(int A[], int );
void binary_serch(int A[], int );

int size = 0;

int main()
{

    int num = 0;
    // Taking the size of the array as the input
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int Array[size];
    srand( (unsigned) time(0));  // using current time as seed to generate number.
    Array[0] = (rand() % 10);

    for(int i = 1; i < size ; i++) // Filling the array
        Array[i]  = Array[i-1] + (rand()%10);
    
    printf("The array elements randomly generated in sorted order are \n");
    
    for (int i = 0; i < size; i++){
        printf("%d, ", Array[i]); 
    }
    printf(" \b \b \n");
    printf("Enter the element to be searched in the Array \n");
    scanf("%d", &num);
    
    printf("Linear Search result is : \n ");
    linear_search(Array, num);
    
    printf("Binary Search result is : \n");
    binary_search(Array, num);

}
void linear_search(int A[], int num)
{
    for (int i = 0; i<size; i++){
        if(A[i] == num){
            printf("Element found at position %d \n ", i+1);
            return ;
        }
    }
    printf("Number not found in the array \n");
}
void  binary_search(int B[], int num)
{   
    int compare = 0;
    int lower = 0;
    int upper = size -1;
    int middle = ( lower + upper ) /2; 
    while (lower < upper)
    {
        compare++;
        if (B[middle] == num){
            printf("The index of the number is %d \n The number of comparisons are %d ", middle+1, compare);
            return; 
        }
        else if (num > B[middle])
            lower = middle + 1;
        else
            upper = middle - 1;
        middle = (lower+upper) /2 ;    
    }
    printf("Number not found in the array \n The number of comparisons are %d", compare);
}
