#include<iostream>

using namespace std;

int main(){

    int arr[10] = {2,5,6};

    cout<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<&arr[0]<<endl;

    cout<<*arr<<endl;
    cout<<*arr+1<<endl;

    cout<<*(arr+1)<<endl;
    cout<<arr[1]<<endl;
    cout<<1[arr]<<endl; 

    return 0;
}