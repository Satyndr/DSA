#include<iostream>

using namespace std;

int main(){

    int arr[5] = {1,2,3,4,5};

    char ch[10]= "adcdefghi";

    cout<<arr<<endl; //it prints the address

    cout<<ch<<endl;//it prints the char array

    char *c = &ch[0];
    
    cout<<c<<endl;//prints the string

    char temp = 'z';
    char *p = &temp;
    cout<<p<<endl;


    return 0;
}