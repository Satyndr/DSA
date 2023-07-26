//Search the position of a element in Rotated sorted array
#include <iostream>
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

int binarySearch (int arr[],int start,int end,int key){
    
    int mid=(start+end)/2;

    while(start <= end){
        
        if (arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
        else {
            end=mid-1;            
        }
        mid = (start+end)/2;
    }
    return -1;
}


int findPosition(int arr[],int size,int key){

    int pivotElement = pivot(arr, size);

    if( key >= arr[pivotElement] && key <= arr[size-1])
    {//BS on second line
        return binarySearch(arr, pivotElement, size-1, key);
    }
    else
    {//BS on first line
        return binarySearch(arr, 0, pivotElement - 1, key);
    }

}

//main function starts here
int main() {

    int arr1[5]={7,8,1,3,5};
    int key;
    cout<<"Enter number to Search: ";
    cin>>key;

    cout<<"Position of number is: "<<findPosition(arr1,5,key);

    return 0;
}