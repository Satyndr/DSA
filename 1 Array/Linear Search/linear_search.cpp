#include <iostream>
using namespace std;

//Liner Search in array
bool LinearSearch(int arr[] , int n, int key){
    for (int i=0;i<n;i++){
        if (key==arr[i]){
            return 1;
        }
    }
    return 0;
}


int main(){

    int arr1[10] = {2, 6, 15, 11, 5, 3, 8, 17, 14, 34};

    int key;
    cout<<"Enter the Key to Search: ";
    cin>>key;

    bool found=LinearSearch(arr1, 10, key);
    if (found){
        cout<<"Number is present in array"<<endl;
    }
    else{
        cout<<"Number not Found!"<<endl;
    }

    return 0;
}