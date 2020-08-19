/*
In this program we will see the types of the variables types
- int --SYSTEM DEPENDENT (SD)
- long --> SYSTEM INDEPENDENT SIZE (SI) "4 bits" also written as "long int"
- short --> SYSTEM INDEPENDENT SIZE
- char ------> Also a type of an integer    
       ...
**ON A 16 BIT SYSTEM TYPE int HAS SAME SIZE AS short
** TYPE int IS ACESSED FASTER THAN short 
*/

#include <iostream>
using namespace std;

int main(){
    int var1;
    int var2; 
    // The above line initialize two memory Locations which have size dependent on the system
    // i.e it occupies 4 bits on Windows and 2 bits on MS-DOS.
    var1 = 10;
    var2 = 18;
    cout << "Value of var1 is now: ";
    cout << var1 << endl;
    cout << "Value of var2 is now: ";
    cout << var2 << endl;
    // The 'endl' is a keyword, used to add a linefeed into  a stream
    // It is an example of a manipulator
    //  endl causes the "output buffer to be flushed"
    return 0;
}

/*
Many compilers offer diff. int types represented ad __int(size)
The,
 __int(8) -- > char
 __int(16) -- > short
 __int(32) -- > short and long both.


*/

//  Standard Cpp provides wchar_t to handle foreign languages
