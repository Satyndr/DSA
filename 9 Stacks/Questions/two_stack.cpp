#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class TwoStack {

public:

    int *arr;
    int top1;
    int top2;
    int size;

    // Initialize TwoStack.
    TwoStack(int s) {

        this -> size = s;        
        top1 =  -1;
        top2 = s;
        arr = new int[s];

    }
    
    // Push in stack 1.
    void push1(int num) {
        if( top2-top1 > 1){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if( top2-top1 > 1){
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if( top1>=0){
            int temp = arr[top1];
            top1--;
            return temp;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if( top2<size){
            int temp = arr[top2];
            top2++;
            return temp;
        }
        else{
            return -1;
        }
    }

    int peek1(){
        //check element present or not
        if( top1>=0 ){
            return arr[top1];
        }
        else{
            return -1;
        }
    }

    int peek2(){
        //check element present or not
        if( top2<size ){
            return arr[top2];
        }
        else{
            return -1;
        }
    }

};


int main(){

    TwoStack s1(5);

    s1.push1(1);    
    s1.push1(2);    
    s1.push2(3);    
    s1.push2(4);

    cout<<s1.peek1()<<endl;
    cout<<s1.peek2()<<endl;

    cout<<s1.pop1()<<endl;

    cout<<s1.pop2()<<endl;
   

    return 0;
}