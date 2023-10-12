#include <bits/stdc++.h> 

using namespace std;

class Queue {

        int *arr;
        int first;
        int rear;
        int size;

public:
    Queue() {
        size = 100000;
        arr = new int[size];
        first = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if( first == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        
        if( rear == size){
            cout<<"Queue is Full!"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if( first == rear){
            return -1;
        }
        else{
            int ans = arr[first];
            arr[first] = -1;
            first++;
            if( first == rear){
                first =0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        
        if( first == rear){
            return -1;
        }
        else{
            return arr[first];
        }
    }

    int back() {
        
        if( first == rear){
            return -1;
        }
        else{
            return arr[rear-1];
        }
    }

};

int main(){

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<"Front: "<<q.front()<<endl;
    cout<<"Rear: "<<q.back()<<endl;

    q.dequeue();
    cout<<"After Dequeuing"<<endl;
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Rear: "<<q.back()<<endl;


    return 0;
}