#include<iostream>

using namespace std;

int factorial(int n){

    //base condition
    if(n==1){
        return 1;
    }

    int smallproblem = factorial(n-1);
    int mainproblem = n * smallproblem;//recursive function

    return mainproblem;
}

int main(){

    cout<<factorial(4)<<endl;

    return 0;
}