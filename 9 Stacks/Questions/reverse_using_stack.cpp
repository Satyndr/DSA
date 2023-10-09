#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main(){

    string name = "Satendra";

    stack<char> s1;

    for(int i=0; i<name.length() ;i++){
        s1.push(name[i]);
    }

    string reverse = "";

    while(!s1.empty()){

        reverse.push_back(s1.top());

        s1.pop();
    }    

    cout<<"Reverse is: "<<reverse<<endl;

    return 0;
}