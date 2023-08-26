#include<iostream>

using namespace std;

int findroot(int s, int e, int num){

    if(s<=e){

        int mid = s+(e-s)/2;

        //base case
        if(mid*mid == num){
            return mid;
        }

        //recursive function
        else if(mid*mid < num){
            return findroot(mid+1,e,num);
        }
        else{
            return findroot(s,mid-1,num);
        }
    }
    return e;
}

int main(){

    int num;
    cout<<"Find Sqroot of : ";
    cin>>num;

    int root = findroot(0,num,num);
    cout<<root;


    return 0;
}