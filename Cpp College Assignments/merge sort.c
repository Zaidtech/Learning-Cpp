
#include<stdlib.h>
#include<stdio.h>

int L[100],R[100];

int min(int x, int y) { return (x<y)? x :y; }

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

void mergebytapping(int arr[],int l,int m,int r)
{

    int i, j;
    int n1 = m - l + 1;
    int n2 =  r - m;

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
         R[j] = arr[m + 1+ j];
    }
    if(n1>=n2)
    {
        for(int i=0;i<n2;i++)
        {
            int curr=R[i];
            int tabsize=n1/n2;
            int tappos=find_tab(curr,L,tabsize,n1);
            int index=0;
            if(tappos!=-1)
            {   index=Binarysearch(L,tappos,tappos+tabsize,curr);
            }
            else{
                 index=Binarysearch(L,0,n1,curr);
            }
            int pos=n1-1;
            while(pos>=index)
                 {
                 L[pos+1]=L[pos];
                 pos-=1;

                }
                L[pos]=curr;
                n1++;
        }
        for(int i=0;i<n1;i++)
        {
            arr[i]=L[i];
        }
    }
    else{

        for(int i=0;i<n1;i++)
        {
            int curr=L[i];
            int tabsize=n2/n1;
            int tappos=find_tab(curr,R,tabsize,n2);
            int index=0;
            if(tappos!=-1)
            {   index=Binarysearch(R,tappos,tappos+tabsize,curr);
            }
            else{
                 index=Binarysearch( R,0,n2,curr);
            }
            int pos=n2-1;
            while(pos>=index)
                 {
                 R[pos+1]=R[pos];
                 pos-=1;

                }
                R[pos]=curr;
                n2++;
        }
        for(int i=0;i<n2;i++)
        {
            arr[i]=R[i];
        }
    }


}

void merge(int arr[], int l, int m, int r)
{
    int i, j;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1],R[n2];


    // Making Left and Right sub arrays
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
  for(int i=0;i<k;i++)
  {
    printf("%d ",arr[i]);
  }
printf("\n");
}


void mergeSortTapping(int arr[],int n)
{
   int curr;
   int ls;
   for (curr=1; curr<=n-1; curr = 2*curr)
   {
       for (ls=0; ls<n-1; ls += 2*curr)
       {
           int mid = min(ls + curr - 1, n-1);
           int re = min(ls + 2*curr - 1, n-1);
           mergebytapping(arr, ls, mid, re);
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
           int mid = min(ls + curr - 1, n-1);
           int re = min(ls + 2*curr - 1, n-1);
           merge(arr, ls, mid, re);
       }
   }
}


void printArray(int A[], int size)
{   int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
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

    return 0;
}
