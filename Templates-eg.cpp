
#include <iostream>
using namespace std;

template <typename T>//basically only T is replaced by that particular data type...
inline T const& Max (T const &a, T const &b)// taking two input vars as reference ie the exact copy of the smae vars but diff names
{
	return 	a < b ?b:a;//return the max value
}

int main(){

int i=39;
int j=20;
cout << "Max value is" <<Max(i,j) <<endl;

double f1= 13.5;
double f2= 143.20;
cout << "Max value is"<< Max(f1,f2)<<endl;

string s1= "Hellow";
string s2= "World";

cout << "Max is" << Max( s1,s2);
}

