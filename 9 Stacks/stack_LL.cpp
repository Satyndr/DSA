#include <iostream> 

using namespace std;

class stack{
    
    public:
    int data;
    stack* next;

    stack(){
        this -> next = NULL;
    }

};



int main(){

    stack* S = new stack();

    stack* top = S;

    push(top,2);peek(top);
    push(top,3);peek(top);

    cout<<isEmpty(top)<<endl;

    pop(top);peek(top);
    pop(top);peek(top);

    cout<<isEmpty(top)<<endl;


    return 0;
}