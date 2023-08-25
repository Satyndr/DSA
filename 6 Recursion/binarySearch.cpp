#include<iostream>

using namespace std;

bool binarySearch(int arr[], int start, int end, int key){

    if(start>end){
        return false;
    }
    int mid = start+(end-start)/2;

    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]<key){
        return binarySearch(arr, mid+1,end,key);
    }
    else{
        return binarySearch(arr, start,mid-1,key);
    }
}

int main(){

    int arr[5] = {1,4,7,3,9};

    if(binarySearch(arr,0,4,9)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }

    return 0;
}