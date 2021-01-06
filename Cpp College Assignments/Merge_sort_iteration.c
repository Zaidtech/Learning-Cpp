#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Declaring function defitnition.
void merge_sort(int A[], int n);
void merge_sort_tabbing(int A[], int n);
void Merge(int A[], int l , int mid, int h,int p);
void Merge_tabbing(int A[] , int l, int mid, int h,int p);
int Binarysearch(int A[],int start,int end,int number);
int find_tab(int ele,int A[],int tabsize,int n);

// Declaring Global Arrays Left and Right.

int Left[100];
int Right[100];

void printArray(int A[], int size)
{   int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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
    merge_sort_tabbing(Array1,num);
    printArray(Array1, num);
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
        Merge(A, 0, p/2, n-1,p);
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

void Merge_tabbing(int B[] , int l, int mid, int h,int p)
{
    int i, j;
    int n1 = mid - l + 1;
    int n2 =  h - mid;

    for (i = 0; i < n1; i++){
        Left[i] = B[l + i];
    }
    for (j = 0; j < n2; j++){
         Right[j] = B[mid + 1+ j];
    }
    if(n1>=n2)
    {
        for(int i=0;i<n2;i++)
        {
            int curr = Right[i];

            int tabsize=n1/n2;
            printf("Tab size is : %d", tabsize);
            
            int tab_pos = find_tab (curr,Left,tabsize,n1);
            int index=0;

            if(tab_pos!=-1)
            {   
                index=Binarysearch(Left,tab_pos,tab_pos+tabsize,curr);
            }

            else{
                 index=Binarysearch(Left,0,n1,curr);
            }
            int pos=n1-1;
            
            while(pos>=index)
                 {
                 Left[pos+1]=Left[pos];
                 pos-=1;
                }
                Left[pos]=curr;
                n1++;
        }
        for(int i=0;i<n1;i++)
        {
            B[i]=Left[i];
        }
    }
    else{
        for(int i=0;i<n1;i++)
        {
            int curr=Left[i];
            int tabsize=n2/n1;
            int tab_pos=find_tab(curr,Right,tabsize,n2);
            int index=0;
            if(tab_pos!=-1)
            {   index=Binarysearch(Right,tab_pos,tab_pos+tabsize,curr);
            }
            else{
                 index=Binarysearch( Right,0,n2,curr);
            }
            int pos=n2-1;
            while(pos>=index)
                 {
                 Right[pos+1]=Right[pos];
                 pos-=1;

                }
                Right[pos]=curr;
                n2++;
        }
        for(int i=0;i<n2;i++)
        {
            B[i]=Right[i];
        }
    }
}

int find_tab(int ele,int A[],int tabsize,int n)
{
    int pos=-1;
    for(int i=0;i<n;i+=tabsize)
    {
        if(ele>=A[i]&& ele<=A[i+1])
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



int Binarysearch(int A[],int start,int end,int number)

{
    if(end<=start)
        return (number > A[start])? (start + 1): start;
    int mid = (start + end)/2;
     if(number == A[mid])
        return mid+1;
     if(number > A[mid])
        return Binarysearch(A, mid+1,end, number);
     if(number < A[mid])
    return Binarysearch(A,start,mid-1, number);
}