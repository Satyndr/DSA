//check if the array is sorted and rotated
#include <iostream>

using namespace std;

bool checkSorted_rotated(int arr[],int n){
    int count =0;

    for(int i=0;i<n;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
        if(arr[n-1] > arr[0]){
            count++;
        }

        return count<=1;
    }

}

int main(){
    int arr1[6]={5,6,1,2,3,4};

    if (checkSorted_rotated(arr1, 6)){
        cout<<"Rotated and Sorted. "<<endl;
    }
    else{
        cout<<"Not Rotated and Sorted Sorted"<<endl;
    }

    return 0;
}