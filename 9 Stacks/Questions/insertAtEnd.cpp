#include <bits/stdc++.h> 
#include <stack>

using namespace std;

void solve(stack<int>&inputStack, int x) {
    //base case
    if( inputStack.empty() ) {
        inputStack.push(x);
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack,x);
    
    inputStack.push(num);
    
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl;

    s = pushAtBottom(s, 4);

    cout<<s.top()<<endl;

    return 0;
}