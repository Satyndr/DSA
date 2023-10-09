#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int element) {
    //basecase
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    insertAtBottom(s, element);
    
    s.push(num);
}

void reverseStack(stack<int> &stack) {

  	//base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}

void display(stack<int> s){

    cout<<"Data: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

int main(){

    stack<int> S;

    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);

    display(S);

    reverseStack(S);

    display(S);

    return 0;
}