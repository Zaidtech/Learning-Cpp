/* Introduction to Structures


*/
#include <iostream>
using namespace std;
#include <iomanip>

//  Defining  a structure
struct part{ // Declaring a structure with the name part
    int model_number; 
    int part_number;
    float cost;
};

// The struct must end with a semicolon ;
int main(){
// Declaring  a struct
part part1; // Defining a variable of the type struct having above defined features
//Acessing the properties of the structure
part1.model_number = 239;
part1.part_number = 889;
part1.cost = 217.78F;


cout<< "Part Model Number" << setw(5) <<part1.model_number <<endl << "Part Cost" <<setw(15)<< part1.cost<< endl;
}



