#include<iostream>

using namespace std;

class Node{

    public:
    int data;
    Node* link;

    Node(int value){
        this -> data = value;
        this -> link = NULL;
    }

};

class Stack {
    Node* top;
 
    public:
    Stack() { top = NULL; }
 
    void push(int data)
    {
 
        Node* temp = new Node(data);
 
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
 
        temp->data = data;
        temp->link = top;
        top = temp;
    }
 
    int peek()
    {
        if ( top != NULL)
            return top->data;
        else
            exit(1);
    }
 
    void pop()
    {
        Node* temp;
 
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else {
            temp = top;
            top = top->link;
            free(temp);
        }
    }
 
};

int main(){

    Stack S1;

    S1.push(1);
    S1.push(2);
    S1.push(3);
    cout<<S1.peek()<<endl;
    S1.pop();
    cout<<S1.peek()<<endl;

    return 0;
}