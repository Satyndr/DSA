#include <iostream>
using namespace std;

//for optimisation of mid formula if the start and end 
//becomes the maximum integer then the sum will be 
//out of range
//mid = start + (end-start)/2

int binarySearch (int arr[],int size,int key){
    
    int start =0;
    int end = size-1;
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

int main() {

    int key;
    cout<<"Enter the number to Find: ";
    cin>>key;

    int arr1[6]={1,2,3,4,5,6};
    int arr2[5]={1,2,3,4,5};

    int index1= binarySearch(arr1, 6, key);
    int index2= binarySearch(arr2, 5, key);

    cout<<index1<<endl;
    cout<<index2<<endl;

    return 0;
}

