#include <iostream>
using namespace std;

class machines{
private:
    int model_no;
public:
// making a default construct...
    machines(){
    }
    // a parameterized one
    machines(int m_no) :model_no(m_no)
    {}
    void functioning(){
        cout << "Preforming some work...";
    }

};

// making a derived class from the class of machines..
class Washing_machine : public machines{
    public:
        void functioning(){
            cout << "Running a washing machine... model no"<< model_no;
        }
};

int main(){
    machines m1;
    m1.functioning();
    Washing_machine m2;;
    m2.functioning();
    
}