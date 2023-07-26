#include <iostream>
using namespace std;

//Code of Selection Sorting
int selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1 ; j<n ; j++ ){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[minIndex],arr[i]);
    }

}

int printArray(int arr[],int n){

    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){

    int arr1[5] = {14, 11, 8, 18, 5};

    selectionSort(arr1,5);

    printArray(arr1,5);

    return 0;
}