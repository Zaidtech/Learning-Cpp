#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;
// fixedflag prevcents the no from beign shown in e  format as 2323e33
// showpoints make sure no always shows a decimal even if it does not have any fractional part
int main()
{
    float fpn = 1234.9;
    cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint) ;
    cout << setprecision(2) << setw(10)<< fpn;

}
