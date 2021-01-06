//Program to sum and subtract the large integer values using concepts of operator overloading.
#include <bits/stdc++.h>
#define LIMIT 100
using namespace std;

class LARGE_INTEGER
{  private:
        int value[LIMIT];
        int length;

    public:
        LARGE_INTEGER();

        friend std::ostream &operator<<(std::ostream &os,LARGE_INTEGER &num)
        {
            for(int i=num.length-1;i>=0;i--)
            {
                os<<num.value[i];
            }
            return os;
        }
        friend istream & operator >> (istream &in,LARGE_INTEGER &num)
        {
            string str;
          int i1,j1,k1;
          cout<<"Enter a number of your choice:";
           cin>>str;
           for(i1=0;str[i1]!='\0';i1++);
          num.length=i1;
          k1=0;
          for(j1=i1-1;j1>=0;j1--)
          {
              num.value[j1]=str[k1++]-48;
          }

        }

        LARGE_INTEGER operator+(LARGE_INTEGER );
        LARGE_INTEGER operator-(LARGE_INTEGER );
        LARGE_INTEGER operator*(LARGE_INTEGER );

};


LARGE_INTEGER::LARGE_INTEGER( )
{
    for ( int i1 = 0; i1 <LIMIT; i1++ )
            value[ i1 ] = 0;
    length=LIMIT-1;
}


LARGE_INTEGER LARGE_INTEGER::operator+( LARGE_INTEGER oper2 )
{
    LARGE_INTEGER temp_value;
    int carry_value = 0;
    int c1,i;
    if(length>oper2.length)
        c1=length;
    else
        c1=oper2.length;
    for ( i=0; i<c1; i++ )
    {
        temp_value.value[ i ] =value[ i ] + oper2.value[ i ] + carry_value;
        if ( temp_value.value[ i ] > 9 )
        {
            temp_value.value[ i ] %= 10;
            carry_value = 1;
        }
        else
            carry_value = 0;
    }
    if(carry_value==1)
    {
        temp_value.length=c1+1;
        if(temp_value.length>=LIMIT)
            cout<<"length exceeded\n";
        else
            temp_value.value[i]=carry_value;
    }
    else
       temp_value.length=c1;
    return temp_value;
}


LARGE_INTEGER LARGE_INTEGER::operator-( LARGE_INTEGER oper2 )
{
    LARGE_INTEGER temp_value;
    int c;
    if(length>oper2.length)
        c=length;
    else
        c=oper2.length;
    int borrow_value = 0;
    if(value[c-1]>=oper2.value[c-1])
    {
        for( int i = 0;i <c;i++)
        {
            if(borrow_value==0)
            {
                if(value[i]>=oper2.value[i])
                {
                   temp_value.value[i]=value[i]-oper2.value[i];
                }
                else
                {
                    borrow_value=1;
                    temp_value.value[i]=value[i]+10-oper2.value[i];
                }
            }
            else
            {
                if(value[i]-1>=oper2.value[i])
                {
                     temp_value.value[i]=value[i]-1-oper2.value[i];
                }
                else
                {
                    borrow_value=1;
                    temp_value.value[i]=value[i]+9-oper2.value[i];
                }
            }
        }
        temp_value.length=c;
    return temp_value;
    }
    else
    {
        cout<<"\nFirst entered number is smaller than second entered number Kindly reenter it.\n"<<endl;

    }

}


LARGE_INTEGER LARGE_INTEGER::operator*( LARGE_INTEGER oper2)
{
    cout<<"Assignment operator"<<"\n";
    if(this == &oper2)
    {
        cout<<"Address same"<<"\n";
        return *this;
    }
    else{
        int *Temp;
        Temp=new int[oper2.length];
        for(int i=0;i<oper2.length;i++)
        {
            Temp[i]=oper2.value[i];
        }
        return *this;
    }
}

int main()
{
    int choice;
    LARGE_INTEGER num1,num2,num3,res;
    printf("Enter your choice\n");
    printf("1.Adding large int\n");
    printf("2.Subtracting large int\n");
    printf("3.Assigning one large int to another large int\n");
    scanf("%d",&choice);
    if(choice==1)
    {
    cin>>num1; 
    cin>>num2;
    cout<<num1<<" ";
    cout <<" + ";
    cout<<num2<<" ";
    res=num1+num2;
    cout<<" = "<<" ";
    cout<<res<<"\n";
    cout << "\n\n";
    }
    else if(choice==2)
    {
     cin>>num1;
    cin>>num2;
    cout<<num1;
    cout <<" - ";
    cout<<num2;
    cout<< " = " ;
    res=num1-num2;
    cout<<res<<"\n";
    }
    else if(choice==3)
    {
        cin>>num1;
        num3=num1;
        printf("After assigning it to another number\n");
        cout<<num3<<"\n";

    }
    else{
        printf("Enter correct choice\n");
    }
    return 0;
}
