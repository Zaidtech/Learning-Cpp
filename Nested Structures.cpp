#include <iostream>
using namespace std;
#include <iomanip>

struct Distance {
    int in_feet;
    float in_inches;
};

struct  Room {
    Distance length; 
    Distance width;

};

int main(){

    Room dining;
    float t_length;
    float t_width;

    dining.length = {13,20.78F}; // {Some feets, Some inches}
    //  Or dining.as_length.in_feet = 13 & dining.as_length.as_inches = 20.78F;

    dining.width.in_feet = 25;
    dining.width.in_inches = 67.23F;

    t_width += dining.width.in_feet+  dining.width.in_inches/12;
    t_length += dining.length.in_feet+  dining.length.in_inches/12;

    cout << "Dining Room Area = "<< t_length * t_width << endl;

    //  For nested structures the initialization goes like this ...
    //  room dining = { {structure_one_member_values}, {structure_two_member_values} } 

}
