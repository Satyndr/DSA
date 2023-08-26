#include<iostream>

using namespace std;

void bubbleSort(int arr[], int size){

    //base case
    if(size==0 || size==1){
        return ;
    }
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    //recursive function
    return bubbleSort(arr,size-1);
}

int main(){

    int arr[8] = {8,7,6,5,4,3,2,1};

    bubbleSort(arr,8);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}