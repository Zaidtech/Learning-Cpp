#include <iostream>
using namespace std;

const int MAX = 100;


class PQueue{
    private:
        int PQ_data[MAX];
        int PQ_priority[MAX];
        int front = -1, rear = -1;
    public:
        void add();
        void remove();
        void print();
};

// to implemet linked list calss
// define it's methods and use the ssame input ouptput procedure for them

class Node {
    public:
        int data;
        int prio_value;
        Node *next;
};

class LinkedList{
    private:
        Node *head;
        // the above is a pointer var of the  type Node and is confined to a link obj..
    public:
        void add_node();
        void display();
        // int Delete(int data);
        // void insert(int data, int pos); ///to be added inte correct position
        // bool isempty();
};

void LinkedList::add_node(){
    int data=0;
    int prio=0;
    Node *new_node = new Node();  // cretaing a node obj
    cout << "Enter the value of Data and it's Priority to be added into the node:-  ";
    cin >>data >>prio; 
    new_node->data = data;
    new_node->prio_value =prio ;
    new_node->next = NULL;
    //  if we are adding a first node then make the head points to it...
    //  else iterate the list unutil reach the end and set the last node pointer to the current;
    if(head == NULL){
        head = new_node; // setting the head pointer to new_node.
    }
    else{
        Node *temp = head;
       cout << "created a new node\n";
        while(temp->next!=NULL && temp->next->prio_value>prio){
            temp = temp->next ;
            cout << "compa\n";
        }
        temp->next = new_node; // setting the last node to the newnode
    }
}


void LinkedList::display(){
    Node *begin = new Node();
    begin = head; // point the begin pointer of type node to the head pointer..
    while(begin != NULL){
        //  cout << "| " << begin->data<< " | * ----> ";
        cout << "Element = "<<begin->data << "\t"<< "Priority = "<< begin->prio_value<< "\n";
        begin = begin->next;
        }
        cout << "NULL";
        cout << endl;
}

int main(){

  LinkedList * list = new LinkedList();
  list->add_node();
  list->add_node();
  list->add_node();
  list->add_node();
  list->add_node();
  list->display();
    return 0;
}