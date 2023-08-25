#include<iostream>

using namespace std;

void printDigit(int n, string arr[]){
    
    //base case
    if(n==0){
        return ;
    }

    //processing
    int digit = n%10;
    n = n/10;

    //recursive function
    printDigit(n,arr);

    cout<<arr[digit]<<" ";
    
}

int main(){

    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cin>>n;

    printDigit(n,arr);

    return 0;
}