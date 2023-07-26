//find the same elements in two arrays and return -1 if no any number is same.
#include <iostream>
using namespace std;

int main() {

    int arr1[5]={1,2,3,4,5};
    int arr2[5]={2,6,7,8,5};


    for (int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<",";
            }
        }
    }
    cout<<"\b ";

    return 0;
}