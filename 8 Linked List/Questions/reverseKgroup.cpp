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


    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
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

//function to print list
void print(node* &head){

    node* temp = head;

    cout<<"Data = ";
    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }cout<<endl;
}

//reverse in k groups
void reverse(node* &head, int k){

    
}

int main(){

    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);
    
    print(head);

    reverse(head,2);
    print(head);

    return 0;
}