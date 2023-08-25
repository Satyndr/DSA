#include<iostream>

using namespace std;

//head recursion
void printcounting1(int n){
    if(n==0){
        return ;
    }
    cout<<n<<endl;
    printcounting1(--n);    
}

//tail recurion
void printcounting2(int n){
    if(n==0){
        return ;
    }

    printcounting2(--n);    

    cout<<n<<endl;
}

int main(){

    int n;
    cin>>n;

    printcounting1(n);
    printcounting2(n);

    return 0;
}