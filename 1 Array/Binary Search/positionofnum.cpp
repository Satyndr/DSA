//print the start and end position of number repeated/present in the array
//also print the total number of occurernce

#include <iostream>
using namespace std;

int firstPosition(int arr[], int n, int k){

    int s=0,e=n-1;
    int ans;
    int mid = s + (e-s)/2;

    while(s <= e){
        if(k == arr[mid]){
            ans = mid;
            e=mid-1;
        }
        else if(k > arr[mid]){
            s= mid+1;
        }
        else {
            e= mid-1;
        }
        mid = s + (e-s)/2;
    }   
    return ans;
}
int LastPosition(int arr[], int n, int k){

    int s=0,e=n-1;
    int ans;
    int mid = s + (e-s)/2;

    while(s <= e){
        if(k == arr[mid]){
            ans = mid;
            s =mid+1;
        }
        else if(k > arr[mid]){
            s= mid+1;
        }
        else {
            e= mid-1;
        }
        mid = s + (e-s)/2;
    }   
    return ans;
}


int main() {

    int arr1[6]={1,2,3,3,4,5};

    cout<<"First Occurence: "<<firstPosition(arr1,6,3)<<endl;
    cout<<"Last Occurence: "<<LastPosition(arr1,6,3)<<endl;
    cout<<"Total Occurence: "<<LastPosition(arr1,6,3)-firstPosition(arr1,6,3)+1<<endl;

    return 0;
}