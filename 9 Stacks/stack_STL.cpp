#include<iostream>
#include<stack>

using namespace std;


int main(){

    stack<int> Stack1;

    Stack1.push(1);
    Stack1.push(2);
    Stack1.push(3);

    cout<<Stack1.top()<<endl;

    cout<<Stack1.size()<<endl;

    Stack1.pop();
    cout<<Stack1.top()<<endl;

    cout<<Stack1.empty()<<endl;

    return 0;
}