
#include<stdlib.h>
#include<stdio.h>
//tab size is always one as always sub-array differs by 1 or 0.
const int tab=1;


void printArray(int A[], int size)
{   int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int minimum(int x, int y) { return (x<y)? x :y; }
//Using binary search to find the position of element to be inserted.
int binary_search(int array[],int size,int x)
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
//Tabbing function to calculate.
void tabbing(int a[], int beg, int end)


{
    int temp, i, j, locate;
    for (i = beg + 1; i <= end; i++)
    {
        temp = a[i];
        j = i - 1;
        locate=binary_search(a,j,temp);
        while (j>=locate)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}


void mergeTapping(int arr[],int l,int m,int r)
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
void merge(int arr[], int l, int m, int r,int n)
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
    printArray(arr,n);

}
void mergeSortTapping(int a[], int n){
    int i, size, beg, mid, end;
    for (i = 0; i < n; i+=tab)
        tabbing(a, i, minimum((i+1), (n-1)));
    for (size = tab; size < n; size = 2*size)
    {
        for (beg = 0; beg < n; beg += 2*size)
        {
            mid = beg + size - 1;
            end = minimum((beg + 2*size - 1), (n-1));
            mergeTapping(a, beg, mid, end);
        }
    }
}

void mergeSortNonRecur(int arr[], int n)
{
   int curr;
   int ls;
   for (curr=1; curr<=n-1; curr = 2*curr)
   {
       for (ls=0; ls<n-1; ls += 2*curr)
       {
           int mid = minimum(ls + curr - 1, n-1);
           int re = minimum(ls + 2*curr - 1, n-1);
           merge(arr, ls, mid, re,n);
       }
   }
}

int main()
{
    int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    printf("Given array is \n");
    printArray(arr, n);
    int choice;
    printf("ENTER ONE FOR NON RECURSIVE MERGE SORT AND TWO FOR TABBING APPROACH \n");
    scanf("%d",&choice);
    if(choice==1)
    {
        mergeSortNonRecur(arr, n);
         printf("\nSorted array is \n");
         printArray(arr, n);
    }
    else if(choice==2)
    {
         mergeSortTapping(arr, n);
         printf("\nSorted array is \n");
         printArray(arr, n);
    }
    else{
        printf("enter correct option\n");
    }


    return 0;
}
