#include <bits/stdc++.h>
using namespace std;

//  creating a class time
class Time
{
    int h,m,s;
    public:
    // constructor with no arg..
    Time()
    {
        h=0, m=0; s=0;
    }

    ~Time(){
        h =0, m = 0, s=0;
    }
    // overloading '+' operator
    Time operator+(Time);
    friend ostream& operator << (ostream &out, Time &tm); 
    friend istream& operator >> (istream &in, Time &tm);
    friend bool operator==(Time &t1, Time &t2); 

    Time operator= (const Time &tm) 
    {   
        cout << "\n";
        h = tm.h;
        m = tm.m;
        s = tm.s;
    }  
};
//  overloading the cout << operator
ostream& operator << (ostream &out, Time &tm)
{
    out << "Time is: " << tm.h << " hour : " << tm.m << " min : " << tm.s << " sec";
    return out;
}

istream& operator >> (istream &in, Time &tm)
{
  string str;
  tm.h =0;
  tm.s =0;
  tm.m =0;
  int h[2] = {0};
  int m[2] = {0};
  int s[3] = {0};
  int hi=0;
  int mi=0;
  int si=0;
  int count = 0;
  cout << "Enter time as hh:mm:ss : ";
  
  cin >> str;
  
  for(int i =0; i< str.length(); i++){
      if (str[i] != ':'){
          if (count == 0){
            // add elements to the hours until first ':' 
              h[hi] = (str[i] - 48);
              hi++;
          }
          // add elements to the min until  second  ':' 
          else if (count ==1){
              m[mi] = (str[i]- 48);
              mi++;
          }
          else{
              s[si] = (str[i] - 48);
              si++;
          }
      }
      else{
          count++;
      }    
  }
//    getting time from the array of h[],m[], s[] into tm
  tm.h = h[0]*10+h[1]*1;
  tm.m = m[0]*10+m[1]*1;
  tm.s = s[0]*10+s[1]*1;
}

//  checking weahter the time objs  are equal  
bool operator== (Time &t1, Time &t2)
{
    return ( t1.h == t2.h && t1.m == t2.m && t1.s == t2.s);
}

Time Time::operator+(Time t1)	//operator function
{
    // creating an obj time
    Time time;
    int a,b;
    a = s+t1.s;
    time.s = a%60;   //getting the total no of seconds
    b = (a/60)+m+t1.m; // b stores the total no of min..
    time.m = b%60;  
    time.h = (b/60)+h+t1.h;
    time.h = time.h%12;
    return time;
}

int main()
{
    Time t1,t2,t3;    
    cin >> t1;
    cin >> t2;
    t3 = t1 + t2;
    cout << "\n";	//adding of two time object using '+' operator
    cout << "Total --> ";
    cout << t3;
    cout << "\n \n";
    cout << "Comaparing t1 and t2: ";
    if(t1 == t2)
    {
        cout << "Both the time values are equal \n ";
    }   
    else 
    {
        cout << "Both the time values are not equal \n ";
    }
    cout << "Assigning from one obj ie. t1 to other t4 :\n ";
    Time t4 = t1;
    cout << t4;
    cout << "\n";
    return 0;
}

// constructor , destructor X
//  = X
//  == X
//  + X
//  >> X
//  << X

