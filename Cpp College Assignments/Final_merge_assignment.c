#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Declaring function defitnition.
void merge_sort(int A[], int n);
void merge_sort_tabbing(int A[], int n);
void Merge(int A[], int l , int mid, int h,int p);
void Merge_tabbing(int A[] , int l, int mid, int h,int p);
int Binarysearch(int A[],int ,int);
int find_tab(int ele,int A[],int tabsize,int n);
int minimum(int x, int y) { return (x<y)? x :y; }
// Declaring Global Arrays Left and Right.
const int tab=1;
int Left[100];
int Right[100];

    

void printArray(int A[], int size)
{   int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int Binarysearch(int array[],int size,int x)

{
   
   int l=0,h,mid;
    h=size;
    mid=(l+h)/2;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(x==array[mid])
        {
            return mid;
            break;
        }
        else if(x<array[mid])
            h=mid-1;
        else
            l=mid+1;
    }
}

void tabbing(int a[], int beg, int end)
{
    int temp, i, j, locate;
    for (i = beg + 1; i <= end; i++)
    {
        temp = a[i];
        j = i - 1;
        locate=Binarysearch(a,j,temp);
        while (j>=locate)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int  main(){

    int num =0;
    printf("Enter number of terms to be generated: ");
    scanf("%d", &num);
    
    int Array[num];
    int Array1[num];

    srand(time(0));
    for(int i=0; i<num;i++){
        Array1[i] = Array[i] = (rand()%100) ;
        
    }
    printf("Random array generated of length %d is : ",num);
    for(int i=0; i<num;i++){
        printf("%d,",Array[i]); 
    }
    printf("\b \b \n");
    merge_sort(Array, num);
    // printArray(Array, num);
    merge_sort_tabbing(Array1,num);
    printArray(Array, num);
}

void merge_sort(int A[], int n){
    int p =2;
    int i=0;
    int l=0;
    int mid=0;
    int h =0;

    //  Iterating over the pairs of subarrays 
    printf("          \n -------  MERGING USING SIMPLE MERGE ---------\n \n ");
    for(p =2; p<=n; p = p*2){
        for(i = 0; i+p-1 < n; i = i+p){
            l = i;
            h = i+p-1;
            mid = ceil((l+h)/2);
            
            Merge(A, l,mid, h,p);
        }
    }

    if(p/2 < n){
        Merge(A, 0, p/2, n-1 ,p);
    }
}

void merge_sort_tabbing(int B[], int n){
    int p =2;
    int i=0;
    int l=0;
    int mid=0;
    int h =0;

    //  Iterating over the pairs of subarrays 
     printf("          \n -------  MERGING USING  TABBING PROCESS  ---------\n \n ");

    for(p =2; p<=n; p = p*2){
        for(i = 0; i+p-1 < n; i = i+p){
            l = i;
            h = i+p-1;
            mid = ceil((l+h)/2);
            Merge_tabbing(B, l,mid, h,p);

        }
    }

    if(p/2 < n){
        Merge_tabbing(B, 0, p/2, n-1,p);
    }
}

void Merge(int A[], int l , int mid, int h, int p){
    
    int i,j,k;

    i = l;
    j = mid+1;
    k = l;

    int call =1;
    call*=2;
    

    int B[h+1];

    while(i <= mid && j <= h)
    {
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        }
        
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
        // Filling the remaining elements
        while(i<=mid){
            // printf("%d ", A[i]);
        B[k++] = A[i++];
        }
        while(j<=h) {
            //  printf("%d ", A[j]);
       B[k++] = A[j++];
        }

        if(call == p){
        printf("AFTER SIMPLE MERGING PAIRS: ");
        }
        else{
            printf("FINAL MERGED ARRAY IS : ");
        }
        for(int x=l; x<=h; x++){
            A[x] = B[x];
            printf(" %d  ", A[x]);
        }
        printf("\n");

}

//  Merging using the tabbing method

void Merge_tabbing(int arr[] , int l, int m, int r,int p)
{
 int i, j;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1],R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
         R[j] = arr[m + 1+ j];
    }
     printf("[ [");
    for (int i = 0; i < n1; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d ", L[i]);
    }
    printf("], [");
    for (int i = 0; i < n2; i++)

    {
        if (i != 0)
            printf(", ");
        printf("%d ", R[i]);
    }
    printf("] ]\t");
    printf("\n");

    i = 0;
    j = 0;
   int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

int find_tab(int ele,int A[],int tabsize,int n)
{
    int pos=-1;
    for(int i=0;i<n;i+=tabsize)
    {
        if(ele>=A[i]&& ele<=A[i+tabsize])
        {
            pos=i;
            break;
        }
    }
    if(pos!=1)
    {
        return pos;
    }
    else{
        return -1;
    }

}
