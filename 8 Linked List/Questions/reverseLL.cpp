#include<iostream>

using namespace std;

class node{

    public:
    int data;
    node* next;

    node(int value){
        this -> data = value;
        this -> next = NULL;
    }

    ~node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }

};

//function to insert at head
void insertAtHead(node* &head, int value){

    node* temp = new node(value);
    temp -> next = head;
    head = temp;

}

//function to insert at end
void insertAtTail(node* &tail, int value){
    
    node* temp = new node(value);

    tail->next=temp;
    tail = temp;

}

void rev(node* &head, node* prev, node* current){


    //base case
    if(current == NULL){
        head = prev;
        return;
    }

    node* forward = current -> next;
    rev(head,current,forward);
    current->next = prev; 
}

void reverse(node* &head){ 

//to reverse using recursion
    node* prev = NULL;
    node* current = head;
    rev(head, prev, current);


//to reverse linked list by looping

    // if(head == NULL || head-> next == NULL){
    //     return ;
    // }

    // node* prev = NULL;
    // node* current = head;
    // node* forward = NULL;
    
    // while(current!= NULL){
    //     forward  = current -> next;
    //     current -> next = prev;
    //     prev = current;
    //     current = forward;
    // }
    // head = prev;

}


//function to print Linked List
void print(node* head){

    node* temp = head;

    cout<<"Data = ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main(){

    node* obj1 = new node(10);
    
    node* head = obj1;
    node* tail = obj1;
    print(head);

    insertAtHead(head, 9);
    insertAtTail(tail, 11);  
    insertAtTail(tail, 12);  
    insertAtTail(tail, 13);  
    insertAtTail(tail, 14);
    print(head);

    reverse(head);
    print(head);  


    return 0;
}