#include<iostream>

using namespace std;

// Return minimum index
int minIndex(int arr[], int i, int j){
    if (i == j)
        return i;
 
    // Find minimum of remaining elements
    int k = minIndex(arr, i+1, j);
 
    // Return minimum of current and remaining.
    return (arr[i] < arr[k])? i : k;
}
 

void SelectionSort(int arr[], int n, int index = 0){
    // Return when starting and size are same
    if (index == n)
       return;
 
    // calling minimum index function for minimum index
    int k = minIndex(arr, index, n-1);
 
    // Swapping when index and minimum index are not same
    if (k != index)
       swap(arr[k], arr[index]);
 
    // Recursively calling selection sort function
    SelectionSort(arr, n, index + 1);
}

int main(){

    int arr[8] = {8,7,6,5,4,3,2,1};

    SelectionSort(arr,8,0);

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}