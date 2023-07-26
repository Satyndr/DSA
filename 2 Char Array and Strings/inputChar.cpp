#include <iostream>

using namespace std;

//function for getting the length of a string
int getLength(char arr[]){
    int count =0;
    for(int i=0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}

//function for getting reverse of a string 
void getReverse(char arr[]){
    int n = getLength(arr);

    int s=0;
    int e = n-1;

    while(s<e){
        swap(arr[s++],arr[e--]);
    }
}

int main() {

    char name[20];//character array initialisation

    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<<"Your name is "<<name;

    // name[2] = '\0';

    cout<<endl;
    cout<<name<<endl;

    //length of string
    cout<<"Length is: "<<getLength(name)<<endl;

    //reverse string
    cout<<"After Reversing"<<endl;
    getReverse(name);
    cout<<name;
    

    return 0;
}