#include <iostream>
using namespace std;


int main(){

    const unsigned char WHITE = 219; // represents a solid black color block
    const unsigned char GRAY  = 176; // represents a solid white color block
    unsigned char ch;
    
    for (int count =0; count < 80*25-1; count++)
    {
        ch = WHITE;
        for(int j = 2; j<count; j++)
        {
            if(count%j == 0){
                ch = '\xB2';
                break;
            }
            cout << ch;
        }
    }
        return 0;
}

//  To be worked upon...