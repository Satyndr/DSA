#include<iostream>

using namespace std;

bool izsort(int arr[], int size){

    //base case
    if(size==0 || size==1){
        return true;
    }

    //rec cond
    if(arr[0]>arr[1]){
        return false;
    }

    bool remainingPart = izsort(arr + 1 , size-1);
    return remainingPart;

}

int main(){

    int arr[5]  = {1,2,3,4,5};
    
    if (izsort(arr,5)){
        cout<<"Sorted";
    }
    else{
        cout<<"Not Sorted";
    }


    return 0;
}