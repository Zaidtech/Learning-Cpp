#include <iostream>
using namespace std;

static int add(int no){

    static int sum = 0;                                                                                                      
    return (sum+=no);
}

int main(){
    int n =0;
    n = 23;
    for(int i=0;i>=0;i++) 
     cout << add(23)<<"\n";

}