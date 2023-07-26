//Shift all the zeroes to right of the array

#include <iostream>
using namespace std;

int moveZero(int arr[], int n){
    int nonZero=0;

    for(int j=0;j<n;j++){
        if(arr[j] != 0){
            swap(arr[j], arr[nonZero]);
            nonZero++;
        }
    }
}

int printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr1[6] = {2,0,1,4,0,7};

    moveZero(arr1, 6);

    cout<<"After";
    printArray(arr1,6);

}