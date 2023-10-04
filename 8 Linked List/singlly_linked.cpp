#include<iostream>

using namespace std;

//node creation
class node{

    public:
    int data;
    node* next;

    //constructor
    node(int value){
        this->data = value;
        this->next = NULL;
    }

    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
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

//function to insert at position
void insertAtKey(node* &head, node* &tail, int value, int key){

    //if key is first
    if(key==1){
        insertAtHead(head,value);
        return;
    }

    node* temp = head;
    for(int i=1;i<key-1;i++){
        temp = temp->next;
    }

    //if key is last
    if(temp-> next == NULL){
        insertAtTail(tail,value);
        return;
    }

    node* nodeToInsert = new node(value);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

void deleteAtPosition(node* &head, node* &tail, int key){

    if(key == 1){
        node* temp = head;
        head= head->next;
        temp->next = NULL;
        delete(temp);

    }
    else{
        node* current = head;
        node* prev = NULL;

        for(int i=1;i<key;i++){
            prev = current;
            current = current->next;
        }
        prev->next=current->next;
        current -> next = NULL;
        delete(current);
    }
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

    node* node1 = new node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    node* head = node1;//this is head
    node* tail = node1;//this is tail

    print(head);
    insertAtHead(head, 12);print(head);
    insertAtHead(head, 11);print(head);

    insertAtTail(tail, 13);print(head);
    insertAtTail(tail, 14);print(head);

    insertAtKey(head,tail,23,2);print(head);
    insertAtKey(head,tail,25,3);print(head);

    deleteAtPosition(head,tail,3);print(head);
    deleteAtPosition(head,tail,1);print(head);


    return 0;
}