#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void insert(int []);
struct position search(int [], int);
void delete(int [], int);
void Linear_probing_insert(int [], int);
void Quadratic_probing_insert(int [], int);
void Double_hashing_insert(int [], int);
void Chaining_insert(int);

int N;
int Hash_table_linear[50] ;
int Hash_table_quad[50] ;
int Hash_table_dhash[50];
int Hash_table_chaining[50][5];

struct position{
    int pos_linear;
    int pos_qaud ;
    int pos_dhash;
    int hash_value;
    int i;
};
    
int main(){
    printf("Generating array of 40 random numbers. \n");
    int Array[40];

    srand(time(0));
    for(int i=0;i<40;i++){
        Array[i] = (rand()%1000);
    }
    printf("Array Generated is \n");
    
    for(int i=0; i<40;i++){
        printf("%d ", Array[i]);
    }

    printf(" \n \n");
    insert(Array);
    printf("\n ");
    //Taking input N to perform operations like insertion and Deletion
    printf("Enter a key to perform hashing operations :  \n");
    scanf("%d", &N);
    printf("Performing search to find %d ... \n", N);
    search(Array, N);  // will be calling the search opration which will be calling the rest..
    printf("Performing deletion to delete %d  from all tables ... \n", N);
    delete(Array, N);
}

void insert(int A[]){
    
    
    printf("                      Insertion using Linear Probing            \n");
    printf("---------------------**********************************------------------  \n");
    for(int i=0; i< 40;i++){
        Linear_probing_insert(Hash_table_linear, A[i]);
    }

    printf("\n \n");
    printf("                      Insertion using Qaudartic Probing         \n");
    printf("---------------------************************************------------------  \n");
    for(int i=0; i< 40;i++){
    Quadratic_probing_insert(Hash_table_quad, A[i]);
    }
    
    printf("\n \n");
    printf("                     Insertion using Double hashing Probing         \n");
    printf("---------------------***************************************------------------  \n");
    for(int i=0; i< 40;i++){
    Double_hashing_insert(Hash_table_dhash, A[i]);
    }
    
    printf("\n \n");
    printf("                     Insertion using Chaining Method       \n");
    printf("---------------------***************************************------------------  \n");
    for(int i=0; i< 40;i++){
    Chaining_insert(A[i]);
    }
}

struct position search(int A[], int N){
    int key =N;
    int hash_value =0;
    int hash_value2 =0;
    int count =0;
    hash_value2 = 7 - (key % 7);
    hash_value = (key % 47);
    struct  position p;

    printf("\n");
    printf(" Searching number %d using Linear probing ... \n ", N);   
    for(int i=0; i< 50; i++){
        if(Hash_table_linear[ (hash_value+i)% 50]  == key){
        p.pos_linear = (hash_value+i) %50;
        printf(" Position --> %*d    Probes --> %d \n", 4,p.pos_linear,i+1);
            count ++;
            break;
        }
        else count = 0;
    }
    if(count ==0) printf("-1  NOT FOUND\n ");
    
    printf(" Searching number %d using Quadratic probing ... \n ", N);
    count =0 ;
    for(int i=0; i< 50; i++){
        if(Hash_table_quad[ (hash_value + i*i) % 50 ] == key){
        p.pos_qaud = (hash_value + i*i) % 50;
        printf(" Position --> %*d    Probes --> %d \n",4, p.pos_qaud,i+1);
            count ++;
            break;        
        }
    }
    if (count ==0) printf("-1  NOT FOUND \n");

    hash_value2 = 7 - (key % 7);
    hash_value = (key % 47);
    printf(" Searching number %d using Double hashing probing ... \n ", N);
    count =0 ;
    for(int i=0; i< 50; i++){
        if( Hash_table_dhash[ ((hash_value + i*hash_value2) % 50) ] == key){
        p.pos_dhash = ((hash_value + i*hash_value2) % 50);
        printf(" Position --> %*d    Probes --> %d \n ",4 ,p.pos_dhash, i+1);
            count ++;
            break;        
        }
    }

    if (count ==0) printf("-1  NOT FOUND \n");
    
    printf(" Searching number %d using Chaning method ... \n ", N);
    count =0 ;
    for(int i=0; i< 50; i++){
        if(Hash_table_chaining[(hash_value) % 50 ][i] == key) {
            p.hash_value = hash_value;
            p.i = i;
            printf(" Position --> [%*d][%d]    Probes --> %d \n ",2,p.hash_value, p.i, i+1);
            // p.pos_chaning  = {hash_value,i};
            count ++;
            break;        
        }
    }
    if (count ==0) printf("-1  NOT FOUND \n");
    return p;

    
}

void delete(int A[], int N){
    struct position pos;
    pos = search(A,N);
    printf(" \n Performing deletion for the given number...");
    //  Whenever the key is found set it's value to be INT_MAX i.e +2147483647
    //  Lazy delete...
    Hash_table_linear[pos.pos_linear]  = INT_MAX;
    Hash_table_quad[pos.pos_qaud] = INT_MAX;
    Hash_table_dhash[pos.pos_dhash] = INT_MAX;
    Hash_table_chaining[pos.hash_value][pos.i] = INT_MAX;
    printf(" DELETED  ELEMENT FROM ALL THE TABLES ...\n");

}

void Linear_probing_insert(int H_table[], int key){
    int probe = 0;
    int hash_value = 0;
    hash_value =  (key % 47);
    // printf("Remainder is %d   ", hash_value);
    while(1){
        // printf("Probe Done are %d ", probe);
        if(H_table[(hash_value+probe)] == 0)
        {
            if((hash_value+probe) < 50)
            {       
                    // printf("Position is %d and redirecting to %d ", (hash_value), (hash_value + probe));
                    H_table[ (hash_value+ probe) ] = key;  
                    printf("    Key --> %*d     Position --> %*d  Probes ---> %d\n",5,key,5, (hash_value+probe), probe+1);              
                    break;
            }
            else 
            {   
                // printf("Position is %d and redirecting to %d ", (hash_value), (hash_value + probe));
                H_table[ ((hash_value+probe)% 50) ] = key;
                printf("    Key --> %*d     Position --> %*d     Probes ---> %d\n", 5, key,5, (hash_value+probe), probe+1);
                break;   
            }
        }
        else
        {   
            probe++;
        }   
    }
}

void Quadratic_probing_insert(int H_table[], int key){
int probe = 0;
    int hash_value = 0;
    hash_value =  (key % 47);
    while(1){
        if(Hash_table_quad[(hash_value+probe*probe)] == 0)
        {
            if((hash_value + probe*probe) < 50)
            {       
                Hash_table_quad[ (hash_value+ probe*probe) ] = key;  
                printf("    Key --> %*d     Position --> %*d     Probes ---> %d\n", 5,key,5, (hash_value+probe*probe), probe+1);              
                break;
            }
            else 
            {   
                Hash_table_quad[ ((hash_value+probe*probe)% 50) ] = key;
                printf("    Key --> %*d     Position --> %*d     Probes ---> %d\n",5,key, 5,(hash_value+probe*probe), probe+1);
                break;   
            }
        }
        else
        {   
            probe++;
        }   
    }
}

void Double_hashing_insert(int H_table[], int key){
    int probe = 0;
    int hash_value1 = 0;
    int hash_value2 = 0;
    //  Defining Hash functions
    hash_value1 =  (key % 47);
    hash_value2 = 7 - (key % 7);

    while(1){
        if(Hash_table_dhash[(hash_value1+ probe * hash_value2)] == 0)
        {
            if((hash_value1+ probe *hash_value2) < 50)
            {       
                    Hash_table_dhash[ (hash_value1 + probe*hash_value2) ] = key;  
                    printf("    Key --> %*d     Position --> %*d   Probes ---> %d\n",5,key, 5,(hash_value1+ probe*hash_value2), probe+1);              
                    break;
            }
            else 
            {   
                Hash_table_dhash[ ((hash_value1 + probe*hash_value2)% 50) ] = key;
                printf("    Key --> %*d     Position --> %*d    Probes ---> %d \n \n", 5,key,5,(hash_value1 + probe*hash_value2), probe+1);
                break;   
            }
        }
        else{
            probe++;
        }
    }
}

void Chaining_insert(int key){

    int probe = 0;
    int hash_value = 0;
    //  Defining Hash functions
    hash_value =  (key % 47);
    while(1){
        if(Hash_table_chaining[hash_value][probe] == 0)
        {
            if((hash_value + probe) < 50)
            {       
                    Hash_table_chaining[hash_value][probe] = key;  
                    printf("    Key --> %*d     Position --> [%*d][%d]   Probes ---> %d \n", 5,key,2, hash_value, probe, probe+1);
                    // printf("%*d  ", 4, key);              
                    break;
            }
            else 
            {   
                Hash_table_chaining[ ((hash_value + probe)% 50)][probe] = key;
                printf("    Key --> %*d     Position --> [%*d][%d]    Probes ---> %d \n", 5,key,2,hash_value,probe, probe+1);
                // printf("%*d  ", 4, key);              
                break;   
            }
        }
        else{
            probe++;
        }
    }
} 
