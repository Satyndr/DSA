#include<iostream>

using namespace std;

class node{

    public:
    int data;
    node* prev;
    node* next;

    node(int value){
        this -> data = value;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

//function to add element at beginning
void insertAtHead(node* &head, int value){

    node* temp = new node(value);
    temp -> prev = NULL;
    temp -> next = head;
    head = temp;

}

//function to insert at end
void insertAtTail(node* &tail, int value){

    node* temp = new node(value);

    temp -> prev = tail;
    tail -> next = temp;
    tail = temp;

}

//function to get length of list
int length(node* &head){
    node* temp = head;

    int len=0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

//function to print list
void print(node* &head){

    node* temp = head;

    cout<<"Data = ";
    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }cout<<endl;
}

int main(){

    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    
    print(head);

    insertAtHead(head,9);print(head);
    insertAtHead(head,8);print(head);

    insertAtTail(tail,11);print(head);
    insertAtTail(tail,12);print(head);



    return 0;
}