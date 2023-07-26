#include <iostream>
using namespace std;

int findUnique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans=ans^arr[i];
    }
    return ans;
}

int main() {

    int arr1[9]={1,1,2,3,3,4,4,5,5};

    cout<<findUnique(arr1,9);
    
    return 0;
}