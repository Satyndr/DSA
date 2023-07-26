#include <iostream>
using namespace std;

//Code of Selection Sorting
int insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int temp = arr[i];
        int j= i-1;
        for( ; j>=0 ;j--){
            if( arr[j] > temp ){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int printArray(int arr[],int n){

    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){

    int arr1[5] = {14, 11, 8, 18, 5};

    insertionSort(arr1,5);

    printArray(arr1,5);

    return 0;
}