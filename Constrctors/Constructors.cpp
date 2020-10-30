// Types  of Constructos 
//  1. Default 2. Parameterized  3. Copy Constructors

#include <iostream>
using namespace std;

class Car{
    int id;
    string model;
    public:
    //  constructor initialization data members..
    // "this" keyword which has three main usages 
    // 1. To  Pass current obj as a parameter to a method likr inn LinkedList   L1->display(); 
    // 2. to refer class instance variable
    // 3. to declare indexers... 
    //  IN CONTRAST THE . OPERATOR IS USED TO ACESSS THE MEMBER METHODS OF  A CLASS
    
        Car(){
            this->id = 11;
            this->model = "Maseraati";
        }
}

//  Constructors are Public
//  have no return typre
//  Diff. Signatures
// THE COMPILER AUTOMATICALLY MAKE TWO CONST.   1. DEFAULT  2. COPY CONSTRUCTORS
