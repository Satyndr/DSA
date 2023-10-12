#include <iostream>

using namespace std;

class node{

public:
    int data;
    node* next;

    node(int value){
        this -> data = value;
        this -> next = NULL;
    }

};

class queue {

    node* front;
    node* rear;

public:
    queue(){
        front = rear = NULL;
    }

    //add element 
    void enqueue(int value){

        node* newNode = new node(value);
        if(front == NULL){
            front = rear = newNode;
        }
        else{
            rear -> next = newNode;
            rear = newNode;
        }

    }

    //delete element
    void dequeue(){

        node* temp = front;
        front = front->next;
        temp -> next = NULL;
        free(temp);

    }

    //front element
    int Qfront(){
        return front->data;
    }

    //back element
    int Qback(){
        return rear->data;
    }

};

int main(){

    queue q;

    q.enqueue(1);    
    q.enqueue(2);    
    q.enqueue(3);    
    q.enqueue(4);    
    q.enqueue(5);   

    cout<<q.Qfront()<<endl; 
    cout<<q.Qback()<<endl; 

    return 0;
}