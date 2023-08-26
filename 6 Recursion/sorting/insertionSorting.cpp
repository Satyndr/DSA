#include<iostream>
using namespace std;

void insertionSort(int arr[],int size){
    
    //base case
    if(size<=1){
        return;
    }

    //recursive call
    insertionSort(arr,size-1);

    //process
    int temp = arr[size-1];
    int i = size-2;

    while(i>=0 && arr[i]>temp){
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1] = temp;


}

int main(){

    int arr[8] = {4,8,6,1,5,7,3,2};

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    
    insertionSort(arr,8);

    cout<<"After Sorting: "<<endl;

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}