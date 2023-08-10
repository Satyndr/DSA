#include<iostream>

using namespace std;

int main(){

    int num = 5;

    cout<<num<<endl;

    //defining pointer
    int *ptr = &num;
    // & -> means address of num
    // ptr is a pointer to int 

    //printing address of num
    cout<<"Address : "<<ptr<<endl;

    //accessing value of num
    cout<<"Value : "<<*ptr<<endl; // * -> dereference operator

    //if
    cout<<ptr++<<endl;

    //lets make a pointer to double
    double d = 4.3;
    double *ptr2 = &d;

    //sizes
    cout<<"Size of num: "<<sizeof(num)<<endl;
    cout<<"Size of Pointer to int: "<<sizeof(ptr)<<endl;
    cout<<"Size of pointer to double: "<<sizeof(ptr2)<<endl;

    //initializing null pointer 
    int *nullP = 0;

    *ptr++;
    cout<<"After : "<<num<<endl;


    return 0;
}