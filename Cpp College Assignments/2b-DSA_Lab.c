#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Binary_search(int A[],int start,int end,int number)
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
// void p(int A[],int size)
// {
//     for(int i=0;i<size;i++)
//     {

//         printf("%d ",A[i]);
//     }
//     printf("\n");


}
void Insertion_sort_modified(int A[],int size)
{   
    int compare=0;
    for(int i=1;i<size;i++)
    {
      compare=0;
      int value=A[i];
      int index=i-1;
      int location=Binary_search(A,0,index,value);
      while(index>=location)
      {
          A[index+1]=A[index];
          index=index-1;
          compare++;
      }
      A[index+1]=value;
      printf("Comparisons done at the end of %d pass :-",i);
        printf("%d\n",compare);
        printf("Elements required to move in order to free the proper location of next element at the end of %d pass :- ",i);
        printf("%d\n",compare);
        printf("Array at the end of pass %d is\n",i);
        display_sorted(A,size);
    }
}

void Insertion)sort_simple(int A[],int size)
{
    int compare=0;
    for(int i=1;i<size;i++)
    {   compare=0;
        int value=A[i];
        int index=i;

        while(value<A[index-1]&& index>0)
        {
            A[index]=A[index-1];
            index=index-1;
            compare++;
        }
        A[index]=value;
        printf("Comparisons done at the end of %d pass :-",i);
        printf("%d\n",compare);
        printf("Array at the end of pass %d is\n",i+1);
        display_sorted(A,size);

    }


}
int main() {

       int size;
       int num;
       printf("Enter number of element in array\n");
       scanf("%d",&size);
       int A[size];
    //setting up upper and lower limit for element of array
       int lower = 0, upper = 100;
       srand(time(0));
       for(int i=0;i<size;i++)
       {

           A[i]=(rand() % (upper - lower + 1))+lower;
       }
       printf("Before sorting the array looks like as follows\n");
       for(int i=0;i<size;i++)
       {

          printf("%d ",A[i]);
       }
       printf("\n");
       int choice=0;
       printf("ENTER 1 FOR USING STANDARD INSERTION SORT AND 2 FOR USING MODIFIED INSERTION SORT\n");
       scanf("%d",&choice);
       if(choice==1)
       {

           InsertionSort(A,size);
       }
       else if(choice==2)
       {
            ModifiedInsertionSort(A,size);

       }
       else
       {

           printf("Kindly re enter your choice\n");
       }

       return 0;

}

