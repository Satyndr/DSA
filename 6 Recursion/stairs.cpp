#include<iostream>

using namespace std;

int waysStair(int n){
    
    //base condition
    if(n<0)
    return 0;

    if(n==0){
        return 1;
    }

    //recursive condition
    return waysStair(n-1)+waysStair(n-2);

}

int main(){

    int n= 10;//number of stairs

    cout<<"No of Ways: "<<waysStair(n);

    return 0;
}