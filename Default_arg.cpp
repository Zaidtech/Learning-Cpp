#include <iostream>
using namespace std;

void repchar(char = '*',  int = 45);

//  The above functions is declared with a default value of 45

int main(){

    repchar();
    repchar('%');
    repchar('+', 30);
    // repchar(NULL,90);
    return 0;

}

void repchar(char ch, int n){
    for(int i =0; i <n;i++){
        printf("%c ", ch);
    }
    printf("\n");
}

