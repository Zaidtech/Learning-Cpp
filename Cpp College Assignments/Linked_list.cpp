/*
To 
Create  a link list and perform these operations :- 
> insert at kth pos. **
> display the complete list **
> length() **
> search(x) returns the pos of x in the list
> isempty(), returns true if the list is empty
> delete from kth pos.
*/

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
    //  A poimter is a var whose value is  a pointer to another variable ... 
    // type * var_name = value of the type is the pointer based type ...    
        Node *next;
    //  The above line shows a pointer variable og Type Node named next that stores the value of a node (therofore a type of node) 
};

class LinkedList{

    public :
    Node head;

};

void Printls( Node *n){
    
    while(n!=NULL){
        cout << "| " << n->data<< " | * ----> ";  
        n = n->next;
    }
    printf("NULL \n ");
}

// --------Length of Link list
int len( Node *n){
    int l=0;
    while(n!=NULL){
        n = n->next;
        l++ ;
    }
    return l;
}

int search(Node *n, int data){
    int pos = 0;
    int l = 0;
    l = len(n)-1;
    int  i =0;
    if (n->data == data){
        return 0;
    }
    while(n->next!= NULL){
        pos++;
        n = n->next;
        if(n->data == data) 
        return pos;
    }
    cout << "NOt found in the list ";
    return -1;
}

//   this function call is an example  of call by reference where address of the head (a pointer var) which itself  stores the address
//  of the next  node ie... address of a ponter var ie.  **head_reference...  
void push_node (Node** head_ref, int data){
    Node *new_node = NULL; 
    new_node = new Node();
    new_node->data = data; 
    //  the new _node points to the node which was earlier pointed by head...
    // ie. addess was stores in Head node var
    new_node->next = *head_ref;
    //  head points to the new_node now it is like   head---> new_node----> address in head earlier
    *head_ref = new_node;
}


int insert_after_certain_nodes(Node *pointer_node, int data){
    if (pointer_node->next == NULL){
        cout << "This is the last node \n";
        // Printls(pointer_node);
        return 0;
    }
    Node *new_node_in_btw = new Node(); 
    new_node_in_btw->data = data;
    new_node_in_btw->next = pointer_node->next;
    pointer_node->next = new_node_in_btw;
    return 0;
}


// void Delete(Node *head, Node *to_be_deleted){

//     //  when node to be deleted is head node

//     // if(to_be_deleted == head){
//     //     if(head->next == NULL)
//     //     cout << "There is only one node"
// }

int main(){

    Node *head = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;
    // // allocating memory for the pointer varibles  
    head = new Node();
    second = new Node();
    third = new Node();
    // head.data  = 1;
    // // the above method is used to assign value in C...
    // //  in c++ and java 
    head->data = 1; 
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    //  if address of a node is not mentioned than it is taken as a null ... one.
    // the value of pointer for the third node is explicitly set to NULL ie on passing it to any parameter .. it will be a call by value
    //  and not call by reference  in constrast for that we needx to pass the adress of the pointer node...

    Printls(head);
    cout << "After inserting 30 before Head :\n";
    push_node(&head , 30); //adding a node in the beginnign of the list
    Printls(head);
    
    cout << "After inserting 4 after second place :\n";
    insert_after_certain_nodes(second,4); // at the last of the list
    Printls(head);

    cout << "\n";
    cout << "Searching positin of the element 30 in the list : ";
    cout << search(head,30) << "\n";

    // cout << "After deleting the second element : \n";
    // delete(head, second);

    Printls(head);
    cout << "Length of the link list is " << len(head) << "\n";
    
    return 0;
}




//           First         Second          Third      
    //      +---+---+     +---+---+     +----+----+  
// HEAD    | 1 | o----->| 2 | o-----> | # | # |  
    //      +---+---+     +---+---+     +----+----+     