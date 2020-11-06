    #include <iostream>
    #include <stdlib.h>
    using namespace std;
    #define il int long
    void merge_sort(il [], il );
    void merge(il [], il, il [], il , il []);

    int main() {    
        il N =0;
            cin >> N;
            il A[N];
            for(il i=0; i<N;i++){
                cin >> A[i];
            }
            merge_sort(A, N);
            
            // for(il i=0; i<N;i++){
            //     cout << A[i] << " ";
            // }
            // cout << "\n";
            il sum =0;
            il count =0;

            for(il i =N-1;i>=0;i--){
                count ++;
                sum = max((A[i]*count), sum);
        }
            cout << sum<< endl;
    }

    void merge_sort(il A[],il num){
        il n =0;
        n = num;
        il mid =0;
        // if(n%2==0){
        //     mid = n/2;
        // }
        // else{
        //     mid = n/2 +1;
        // }
        mid = (n%2==0)?(n/2):(n/2+1);
        il Left[n/2];
        il Right[n-mid];
        if(n <2){
        return;
        }    
        for(il i=0;i<mid;i++){
            Left[i] = A[i];
        }    
        for(il i=mid ;i< n;i++){
            Right[i-mid] = A[i];
        }
        merge_sort(Left, mid);
        merge_sort(Right, n-mid);
        merge(Left, mid, Right, n-mid, A);
    }



    void merge(il L[], il sizeL , il R[], il sizeR, il A[]){

        il nL = sizeL;
        // il L[nL];
        il nR = sizeR;
        // il R[nR];
        il i = 0;
        il j=0; 
        il k=0;
        while(i <nL && j<nR){
            if( L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
            k++;
        }
            while(i < nL){
                A[k] = L[i];
                k++;
                i++;
            }
            while(j<nR){
                A[k] = R[j];
                j++;
                k++;
            }
    }