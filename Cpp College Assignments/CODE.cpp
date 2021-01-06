#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int coef;
    int xexp;
    int yexp;
    int zexp;
    Node* prev;
    Node* next;
};

// function 
void Print(Node * head);
void removeDuplicates(Node* start);
Node* Plynomial_multiplication(Node * node1head, Node * node2head);
Node* Append_z(Node* head,int c,int e);
Node* Polynomial_add(Node* node1head,Node* node2head);
Node* Add_Polynomailx(Node* head,int c,int e);
Node* addnode(Node* start, int coeff, int xpower,int ypower,int zpower);

// creating node obj..
Node* node1,node2,result;

void removeDuplicates(Node* start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;


    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;


        while (ptr2->next != NULL) {


            if (((ptr1->xexp)== ((ptr2->next)->xexp))&& ((ptr1->yexp)== ((ptr2->next)->yexp))&&
                ((ptr1->zexp)== ((ptr2->next)->zexp))) {

                // Add their coefficients and put it in 1st element
                ptr1->coef = ptr1->coef+ ptr2->next->coef;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;

                // remove the 2nd element
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

Node* Add_Polynomailx(Node* head,int c,int e)
{
    Node* newnode=new Node();
    newnode->coef=c;
    newnode->xexp=e;
    newnode->yexp=0;
    newnode->zexp=0;

    if(head==NULL)
    {

        newnode->next=NULL;
        return newnode;
    }

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;

    return head;
}

Node* addnode(Node* start, int coeff, int xpower,int ypower,int zpower)
{

    Node* newnode = new Node;
    newnode->coef = coeff;
    newnode->xexp = xpower;
    newnode->yexp=ypower;
    newnode->zexp=zpower;
    newnode->next = NULL;

    // If linked list is empty
    if (start == NULL)
        return newnode;

    // If linked list has nodes
    Node* ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;

    return start;
}

Node* Add_Polynomaily(Node* head,int c,int e)
{
    Node* newnode=new Node();
    newnode->coef=c;
    newnode->xexp=0;
    newnode->yexp=e;
    newnode->zexp=0;

    if(head==NULL)
    {

        newnode->next=NULL;
        return newnode;
    }

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;

    return head;
}
Node* Add_Polynomailz(Node* head,int c,int e)
{
    Node* newnode=new Node();
    newnode->coef=c;
    newnode->xexp=0;
    newnode->yexp=0;
    newnode->zexp=e;

    if(head==NULL)
    {

        newnode->next=NULL;
        return newnode;
    }

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;
}

Node* Append_x(Node* head,int c,int e)
{
    Node* newnode=new Node();
    newnode->coef= c;
    newnode->xexp=e;
    newnode->yexp=0;
    newnode->zexp=0;
    if(head==NULL)
    {
        newnode->next=NULL;
        return newnode;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;

}
Node* Append_y(Node* head,int c,int e)
{
    Node* newnode=new Node();
    newnode->coef= c;
    newnode->xexp=0;
    newnode->yexp=e;
    newnode->zexp=0;
    if(head==NULL)
    {
        newnode->next=NULL;
        return newnode;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;

}

int main()
{
    Node* node1=NULL;
    Node* node2=NULL;
    Node* p3;
    Node* result=NULL;
    int coefficient;
    int xexpo,yexpo,zexpo;
    char character;
    int noofterms;
    //Inputing polynomial 1
    cout<<"Enter the number of terms in  polynomial 1 : ";
    cin>>noofterms;
    cout<<"Enter the Polynomial 1 (highest power first)"<<"\n";
    for(int i=0;i<noofterms;i++)
    {
        cout<<"Choose your variable either x/y/z "<<"\n";
        cin>>character;
        cout<<"Enter the Coefficient and Exponent values: ";
        if(character == 'x'||  character=='X')
        {
            cin>>coefficient>>xexpo;
            node1=Add_Polynomailx(node1,coefficient,xexpo);
        }
        else if(character == 'y'||  character=='Y')
        {
            cin>>coefficient>>yexpo;
            node1=Add_Polynomaily(node1,coefficient,yexpo);
        }
        else if(character == 'z'||  character=='Z')
        {
            cin>>coefficient>>zexpo;
            node1=Add_Polynomailz(node1,coefficient,zexpo);
        }
        else{
            cout<<"Invalid Variable entered"<<"\n";

        }

    }


    ////Inputing polynomial 2
    cout<<"Enter the number of terms in  polynomial 2 : ";
    cin>>noofterms;
    cout<<"Enter the polynomial 2  (highest power first)"<<"\n";
    for(int i=0;i<noofterms;i++)
    {
        cout<<"Choose your variable either x/y/z"<<"\n";
        cin>>character;
        cout<<"Enter the Coefficient and Exponent values: ";
        if(character == 'x'||  character=='X')
        {
            cin>>coefficient>>xexpo;
            node2=Add_Polynomailx(node2,coefficient,xexpo);
        }
        else if(character == 'y'||  character=='Y')
        {
            cin>>coefficient>>yexpo;
            node2=Add_Polynomaily(node2,coefficient,yexpo);
        }
        else if(character == 'z'||  character=='Z')
        {
            cin>>coefficient>>zexpo;
            node2=Add_Polynomailz(node2,coefficient,zexpo);
        }
        else{
            cout<<"Please enter correct variable"<<"\n";

        }

    }
    int choice;
  cout<<"Enter your choice \n 1. Addition \n . 2. Multiplication " << "\n";
  cin>>choice;
  //Printing result
    cout<<"Plynomial 1 is: "<<"\n";
    Print(node1);
    cout<<"Polynomial 2 is: "<<"\n";
    Print(node2);
  if(choice==1)
  {
      //performing addition
    p3=Polynomial_add(node1,node2);
     cout<<"The Sum is : ";
    Print(p3);

  }
else if(choice==2)
{
     p3=Plynomial_multiplication(node1,node2);
    cout<<"The Product is : ";
    Print(p3);
}
else{
    cout<<"Invalid input"<<"\n";

}
}

Node* Polynomial_add(Node* node1head,Node* node2head)
{

    Node* ans=NULL;
    Node* t1;
    Node* t2;
    t1= node1head;
    t2= node2head;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->xexp>t2->xexp)
        {

            ans=Append_x(ans,t1->coef,t1->xexp);
            t1=t1->next;
        }
        else if(t1->yexp>t2->yexp)
        {

            ans=Append_y(ans,t1->coef,t1->yexp);
            t1=t1->next;
        }
        else if(t1->zexp>t2->zexp)
        {

            ans=Append_z(ans,t1->coef,t1->zexp);
            t1=t1->next;
        }
        else if(t1->xexp<t2->xexp)
        {

            ans=Append_x(ans,t2->coef,t2->xexp);
            t2=t2->next;
        }
        else if(t1->yexp<t2->yexp)
        {

            ans=Append_y(ans,t2->coef,t2->yexp);
            t2=t2->next;
        }
        else if(t1->zexp<t2->zexp)
        {

            ans=Append_z(ans,t2->coef,t2->zexp);
            t2=t2->next;
        }
        else if(t1->xexp==t2->xexp)
        {

            ans=Append_x(ans,(t1->coef)+(t2->coef),t1->xexp);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->yexp==t2->yexp)
        {

            ans=Append_y(ans,(t1->coef)+(t2->coef),t1->yexp);
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->zexp==t2->zexp)
        {

            ans=Append_z(ans,(t1->coef)+(t2->coef),t1->zexp);
            t1=t1->next;
            t2=t2->next;
        }

    }

    while(t1!=NULL)
    {

        ans=Append_x(ans,t1->coef,t1->xexp);
        t1=t1->next;
    }
    while(t1!=NULL)
    {

        ans=Append_y(ans,t1->coef,t1->yexp);
        t1=t1->next;
    }
    while(t1!=NULL)
    {

        ans=Append_z(ans,t1->coef,t1->zexp);
        t1=t1->next;
    }
    while(t2!=NULL)
    {
        ans=Append_x(ans,t2->coef,t2->xexp);
        t2=t2->next;
    }
    while(t2!=NULL)
    {
        ans=Append_y(ans,t2->coef,t2->yexp);
        t2=t2->next;
    }
    while(t2!=NULL)
    {
        ans=Append_z(ans,t2->coef,t2->zexp);
        t2=t2->next;
    }

    return ans;

}

Node* Append_z(Node* head,int c,int e)
{
    Node* newnode=new Node();
    newnode->coef= c;
    newnode->xexp=0;
    newnode->yexp=0;
    newnode->zexp=e;
    if(head==NULL)
    {
        newnode->next=NULL;
        return newnode;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;
    return head;

}

Node* Plynomial_multiplication(Node* node1head,Node* node2head)
{
    Node* ans=NULL;
    Node* ptr1;
    Node* ptr2;
    ptr1=node1head;
    ptr2=node2head;
    int c,xe,ye,ze;
    if(node1head==NULL && node2head==NULL)
    {

        cout<<"multiplication of polynomial is not possible"<<"\n";
    }
    else{
        while(ptr1!=NULL)
        {
           ptr2=node2head;
           while(ptr2!=NULL)
           {
               c=ptr1->coef*ptr2->coef;
               xe=ptr1->xexp+ptr2->xexp;
               ye=ptr1->yexp+ptr2->yexp;
               ze=ptr1->zexp+ptr2->zexp;
               ans=addnode(ans,c,xe,ye,ze);
               ptr2=ptr2->next;
           }

            ptr2 = node2head;
        ptr1=ptr1->next;
    }
}

 removeDuplicates(ans);
    return ans;
}

void Print(Node* head)
{
    Node* temp=head;
    if(temp==NULL)
    {

        cout<<"Empty"<<"\n";
    }
    else{
        while(temp->next!=NULL)
        {
            cout<<temp->coef<<"x^"<<temp->xexp<<" + "<<"y^"<<temp->yexp<< " + " <<"z^"<<temp->zexp;
            temp=temp->next;
            cout<<"+";
        }
        cout<<temp->coef<<"x^"<<temp->xexp << " + " <<"y^"<<temp->yexp<< " + "<<"z^"<<temp->zexp<<"\n";

    }
}

