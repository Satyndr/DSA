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


//function to print Linked List
void print(node* head){

    node* temp = head;

    cout<<"Data = ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

node* middleNode(node* head) {

    if(head == NULL || head->next == NULL){
        return head;
    }

    if(head -> next -> next == NULL){
        return head -> next;
    }
    
    node* fast = head -> next;
    node* slow = head ;

    while(fast!=NULL ){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }

    return slow;
}

int main(){

    node* node1 = new node(10);

    node* head = node1;
    node* tail = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 11);
    insertAtTail(tail, 13);
    insertAtTail(tail, 14);print(head);

    //find middle element
    node* middle = middleNode(head);
    cout<<"Middle Node is "<<middle ->data;     

    return 0;
}