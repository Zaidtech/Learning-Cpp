// #include <bits/stdc++.h>
#include <iostream>

using namespace std;


void merge(int long Left[], int long sizeL , int long Right[], int long sizeR, int long B[]){
    int nL = sizeL;
    // int L[nL];
    int nR = sizeR;
    // int R[nR];
    int i = 0;
    int j=0; 
    int k=0;
    while(i <nL && j<nR){
        if( Left[i] <= Right[j]){
            B[k] = Left[i];
            i++;
        }
        else {
            B[k] = Right[j];
            j++;
        }
        k++;
    }
        while(i < nL){
            B[k] = Left[i];
            k++;
            i++;
        }
        while(j<nR){
            B[k] = Right[j];
            j++;
            k++;
        }
}

void merge_sort(int long Array[], int long n){
    int long num = 0;
    num = n;
    int long  mid =0;
    
    if(n<2){
        return ;
    }
    
    if( n%2 ==0){
        mid = n / 2;
    }
    
    else mid = n /2 +1;
    
    int long L[mid];
    int long R[n-mid];
    
    for(int i=0; i<mid;i++) { L[i] = Array[i];}
    for(int j=mid; j<n;j++) { R[j-mid] = Array[j];}
    
    merge_sort(L, mid);
    merge_sort(R, n-mid);
    merge(L, mid, R, n-mid, Array);
}


int main(){
    int T=0;
    int N=0;
    cin >> T;
    while(T--){
        cin >> N;

        int long A[N];
        for(int i=0; i<N; i++){
            cin >> A[i];
        }

        merge_sort(A, N);
        
        int sum =0;
        sum = A[0]+A[1];
        printf("%d \n ", sum);
    }
}
