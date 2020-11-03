#include <iostream>
using namespace std;

class Stack{
    
private:

    // enum {
    //     MAX = 10};  
    // // MAX is the max no of elements in an array
    const static int MAX = 10; 

    int st[MAX];
    int top;

public:
    Stack(){ // constructor
        top =0;}

    // push a no into a stack
    void push(int var)
    {
        st[++top] = var;
    }
    // take a no of the stack
    int pop(){
        return st[top--];
    }
};

int main(){
    Stack s1;
    s1.push(12);

    s1.push(22);
    cout << "1:"<<s1.pop() << "\n";
    cout << "2:"<<s1.pop() << "\n";
}
// 