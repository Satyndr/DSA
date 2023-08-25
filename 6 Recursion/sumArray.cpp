#include<iostream>

using namespace std;

int arrSum(int arr[], int size){

    int ans = arr[0]; 

    if(size==0 || size==1){
        return ans;
    }
    
    ans=ans+arrSum(arr+1,size-1);
    return ans;

}

int main(){

    int arr[5] = {1,2,3,4,5};

    cout<<arrSum(arr,5);

    return 0;
}