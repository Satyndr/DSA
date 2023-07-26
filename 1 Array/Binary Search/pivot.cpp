//find the position of least element in array
#include<iostream> 
using namespace std;

int pivot(int arr[], int size) {
    int s=0, e=size-1;
    int mid = s+(e-s)/2;

    while(s<e){
        if (arr[mid]>arr[0]){
           s=mid+1;
        }
        else{
           e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {

    int arr1[5]={7,9,12,4,5};

    cout<<"Position of pivot Element: "<<pivot(arr1,5);

    return 0;
}