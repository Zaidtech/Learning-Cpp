//  if i is even a[i] < a[i+1] and if i is odd then a[i] > a[i+1];

#include <iostream>
using namespace std;
# define il int long

int main(){
    int T;
    cin >> T;
    il N =0;
    while(T--){
        cin >> N;
        il A[N];
        for(int i=0; i<N;i++){
            cin >> A[i];
        }

        for(int i=0; i<N-1;i++)
        {
            if(i%2==0){
                if(A[i] >= A[i+1]) {
                    il temp =0;
                    temp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = temp;
                }
            }
            else 
            {
                if(A[i] <= A[i+1]){
                    il temp =0;
                    temp = A[i];
                    A[i] = A[i+1];
                    A[i+1] = temp;    
                }
            }

        }   
        for(int i=0; i<N;i++){
            cout << A[i] << " ";

        }
        printf("\n");
    }
}