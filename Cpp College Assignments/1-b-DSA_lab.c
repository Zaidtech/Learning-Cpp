// DSA LAB -- 1(b)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N = 100;
void binary_srch(int B[][N],int rows, int columns, int search){
    int l_r = 0, u_r = rows-1, m_r = (l_r+u_r)/2;
    int l_c = 0, u_c = columns-1, m_c = (l_c+u_c)/2;
    int compare = 0;
    while(l_r <= u_r)
    {
        compare ++;
        if(search <= B[m_r][columns-1] && search >= B[m_r][0])
        {   
            while(l_c <= u_c){
                compare++;
                if(search == B[m_r][m_c])
                {
                    printf("The index of the number is (%d, %d) \n The number of comparisons are %d \n", m_r, m_c, compare);
                    return;
                
                }
            else if(search < B[m_r][m_c])
                u_c = m_c - 1;
            else 
                l_c = m_c +1;
            m_c = (u_c + l_c)/2;            
            }
            printf("The number was not found \n The number of comparisons are %d ", compare);
            return;
        }
        else if (search < B[m_r][0])
            u_r = m_r-1;    
        else
            l_r = m_r + 1;        
        m_r = (l_r + u_r) /2;

        }
        
    printf("No such number found \n The number of comparisons are %d ", compare);
    return ;
    }
int main()
{
    int rows, columns, search;
    printf("Enter the row and column size of the array \n");
    scanf("%d %d", &rows ,&columns);
    
    int Array[rows][N];
    
    srand(time(0));
    Array[0][0] = rand()%10;
    for(int i = 0; i < rows; i++){
        if (i!=0)
        Array[i][0] = Array[i-1][columns-1]+rand()%10;
        for(int j = 1; j<columns; j++)
            Array[i][j] = rand()%10 + Array[i][j-1];
    }
    printf("\n The array elements in sorted order are : \n");
    
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<columns; j++)
            printf("%d ", Array[i][j]);
            printf("\n");
    }
    printf("\nEnter the number to be searched : ");
    scanf("%d", &search);
    printf("\n Binary search result: \n");
    binary_srch(Array, rows, columns, search);
}

