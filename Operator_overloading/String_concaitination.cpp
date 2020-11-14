#include <iostream>
#include <string.h>
using namespace std;
// Below is a simple way of using predefined atring class 
// int main(){
//     string s1 ,s2;
//     s1 = "hi";
//     s2 = " zaid";
//     cout << s1+s2;
// }

// making own string class

class String{

public:
    const static int SZ = 80;
    char str[SZ];

private:
    // a default constructor
    String(){
        strcpy(str, "");
    }
    //  one argument constructor 
    String(char ch[]){
        strcpy(str,ch );
    }
    void display() const  // const defines this method to be of type constant as it cannot alter it's value
    {
        cout << str;
    }
    // overloading the + operator
    String operator+ (Sting ss) const {
        String temp;
        // temp has a memeber char str []
        if (strlen(str) + strlen(ss.str) <SZ){
            strcpy(temp.str, str); // copy the string to the temp var 
            strcat(temp.str, ss.str); // concatinate the new string into the temp var. 
        }
        else{
            cout << "Length excedded ";
        }
        return temp;
    }
};

int main(){

    String str1,str2,str3;
    str1 = "Happy Birthday to you";
    str2 = "Zaid";
    str3 = str1 + str2; 
    str3.display();
}
