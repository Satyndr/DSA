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
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }

};

//to insert at head
void insertAfter(node* &tail, int element, int value){

    if(tail == NULL) {
        node* newNode = new node(value);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        
        node* newNode = new node(value);
        node* current = tail;
        while(current -> data  != element){
            current = current -> next;
        }
        newNode -> next = current -> next;
        current -> next = newNode;

    }
        
}

//to delete the value
void deleteValue(node* &tail, int element){

   //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty
        //assuming that "value" is present in the Linked List
        node* prev = tail;
        node* curr = prev -> next;

        while(curr -> data != element) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        if(curr == prev) {
            tail = NULL;
        }
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }    
}

//to print
void print(node* tail) {

    node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    cout<<"Data : ";
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 


int main(){

    node* node1 = new node(10);
    node1 -> next = node1;

    node* tail = node1;

    print(tail);

    insertAfter(tail,10,11);print(tail);
    insertAfter(tail,11,12);print(tail);
    insertAfter(tail,10,6);print(tail);
    insertAfter(tail,6,8);print(tail);
    insertAfter(tail,10,15);print(tail);

    deleteValue(tail,6);print(tail);
    deleteValue(tail,12);print(tail);
    deleteValue(tail,10);print(tail);


    return 0;
}