#include <iostream>
#include <string> 
using namespace std;

int main(){

    string str1, str2;
    //  Creating two obj of class String
    cout << "Enter first string :";
    cin >> str1;
    cout << "Enter substring to find in first string " << str1 << " :";
    cin >> str2;
    int index=0 ;
    index = str1.find(str2);
    if(index == -1){
        cout << "No such substring found"<<endl;
    }
    else
    cout <<"The index of "<< str2 << " in " << str1<< " is : " << index<< endl;         
}
