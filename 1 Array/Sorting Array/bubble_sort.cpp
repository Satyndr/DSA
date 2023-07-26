//bubble Sorting
#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n){

    for(int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1] ){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//optimised code if no swapping is done
/*
int bubbleSort(int arr[], int n){

    for(int i=1;i<n;i++){
        bool swapped = false;
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1] ){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if (swapped = false){
            break;
        }
    }
}
*/

int printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main() {

    int arr1[5]={7,6,1,10,3};

    bubbleSort(arr1,5);

    printArray(arr1,5);

    return 0;
}