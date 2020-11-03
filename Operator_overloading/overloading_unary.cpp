#include <iostream>
using namespace std;

class Counter{
private:   
    static unsigned int count;
public:
    //  when the first call to the constructor set it's value to 0 
    Counter (){
        count ++;
    }
    Counter (int n){}
    unsigned int get_count(){
        return count;
    }
    // return   type operator name_of_oprator (parameters if it take to operate on)
    Counter operator ++(){ 
        Counter temp;
        // here we copuld have used the concept of nameless temporary obj without using this temp obj.
        ++count;
        // temp.count = count;
        // 
        // printf("The address of this temp id %p", &temp);
        // return temp;
        //  WE COULD HAVE USED THE NAMELESS TEMP VARIABLE APPROACH
        return Counter(count); // makes a Counter obj  without name and assign it the value  of Count
        // thus it requires another constructor
    }
};

unsigned int Counter::count = 0;

int main(){
    Counter c1;
    cout << "\nc1= "<< c1.get_count();
    Counter c2;
    cout << "\nc2= "<< c2.get_count();
    //  moreover i could use the belowq line which  will alter the static value of the  count var.  
    ++c1;
    cout << "\nc1 = "<< c1.get_count();
    cout << "\nc2 = "<< c2.get_count();
    // initialized an obj
    Counter *c3;
    printf("Address of the c3 obj is %p \n", &c3);
    *c3 = (++c2);
    printf("Addrsss osf c3 now is %p \n", &c3);
    Counter c4;
    // (&c4) = &(*c3);
    printf("Address of c4 is %p \n", &c4);
    printf("Address of c3 +somewthing is %p", ((&c3)+10));
}
