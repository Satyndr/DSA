#include <bits/stdc++.h> 
#include <stack>

using namespace std;

void insertSorted(stack<int> &s , int n){

	//base case
	if( !s.empty()&&s.top() <= n || s.empty()){
		s.push(n);
		return;
	}

	int num = s.top();
	s.pop();

	insertSorted(s, n);
	s.push(num);

}
void sortStack(stack<int> &stack)
{

	//base case
	if(stack.empty()){
		return;
	}
	
	int num = stack.top();
	stack.pop();

	sortStack(stack);

	insertSorted(stack, num);

}

void display(stack<int> s){

    cout<<"Data: ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}

int main(){

    stack<int> s;
    s.push(-7);
    s.push(2);
    s.push(-9);
    s.push(3);
    s.push(5);

    sortStack(s);

    cout<<"After Sorted: "<<endl;

    display(s);    

}