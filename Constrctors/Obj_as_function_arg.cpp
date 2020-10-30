#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;
public:
    Distance(): feet(0), inches(0.0)
    {
        
    }
    //                          initializer list 
    Distance(int ft , int in) : feet(ft), inches(in)
    {

    }

    void getdist(){
        cout << "\nEnter feet: "; cin >> feet;
        cout << "\nEnter inches: "; cin >> inches;
    }

    void showData()
    {
        cout << "Feet  is" << feet ;
        cout << "Inches is " << inches << "' ";
    }   
    void add_Distance(Distance d2, Distance d3); //declaration of a function 

};


void Distance::add_Distance(Distance d3, Distance d2){

    inches = d3.inches+ d2.inches ;
    feet = 0;
    if(inches >=12.0)
        {
            inches -= 12;
            feet +=1;
        }
}

int main(){
    Distance dist1, dist3; // calling a default constructor 
    Distance dist2(11, 6.23);

    dist1.getdist();
    dist3.add_Distance(dist1, dist2); 
    dist3.showData();
}