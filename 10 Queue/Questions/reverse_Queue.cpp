#include<bits/stdc++.h>

using namespace std;

void reverseQueue(queue<int> &q){

    //base case
    if(q.empty()){
        return;
    }
    int num = q.front();

    q.pop();
    reverseQueue(q);

    q.push(num);

}

void printQueue(queue<int> q){

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);

    printQueue(q);

    return 0;
}