#include<iostream>

using namespace std;

class stack{

    public:
    //properties
    int *arr;
    int top;
    int size;

    //behaviours
    stack(int value){
        this -> size = value;
        arr = new int[value];
        top = -1; 
    }

    void push(int value){
        //check empty space available or not
        if( size - top > 1){
            top++;
            arr[top] = value;
        }
        else{
            cout<<"Overflow!"<<endl;
        }
    }

    void pop(){
        //check element present or not
        if( top>=0){
            top--;
        }
        else{
            cout<<"UnderFlow!"<<endl;
        }
    }

    int peek(){
        //check element present or not
        if( top>=0 ){
            return arr[top];
        }
        else{
            cout<<"UnderFlow!"<<endl;
            return -1;
        }
    }

    bool empty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

};

int main(){

    stack s1(5);

    s1.push(1);    
    s1.push(2);    
    s1.push(3);    
    s1.push(4);

    cout<<s1.peek()<<endl; 

    s1.pop();
    cout<<s1.peek()<<endl;

    cout<<s1.empty()<<endl;   

    return 0;
}