#include<iostream>

using namespace std;

int fibbo(int n){

    //base case
    if (n==1)
    return 1;

    if (n==0)
    return 0;

    //recursive condition
    return (fibbo(n-1)+fibbo(n-2));

}

int main(){

    int  n;
    cin>>n;
    //n is the number of terms of fibonacci series

    cout<<fibbo(n);
    
    return 0;
}