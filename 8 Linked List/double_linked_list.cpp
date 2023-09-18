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

//function to insert at key
void insertAtKey(node* &head, node* tail, int key, int value){

    if(head == NULL){
        cout<<"Empty !";
        return;
    }

    if(key==1){
        insertAtHead(head, value);
        return;
    }

    node* temp = head;
    for(int i=1;i<key-1;i++){
        temp = temp -> next;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, value);
        return;
    }

    node* nodeToInsert = new node(value);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

//function to delete at beginning
void deleteAtHead(node* &head){

    node* temp = head;
    temp -> next -> prev = NULL;
    head = temp -> next;
    temp -> next = NULL;
    delete temp;
    
}

//delete at position
void deleteAtKey(node* &head, node* &tail, int key){

    if(key == 1){
        node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* current = head;
        node* previous = NULL;

        for(int i=1;i<key;i++){
            previous = current;
            current = current->next;
        }
        current -> next -> prev = previous;
        previous -> next = current->next;
        current -> next = NULL;
        delete(current);
    }
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

    insertAtKey(head,tail,3,13);print(head);
    insertAtKey(head,tail,4,14);print(head);

    deleteAtHead(head);print(head);

    deleteAtKey(head,tail,2);print(head);


    return 0;
}