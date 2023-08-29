#include<iostream>
using namespace std;

void quickSort(int arr[],int s, int e){

    //base case
    if (s>=e){
        return ;
    }

    //yoo

}

int main(){

    int arr[8] = {4,8,6,1,5,7,3,2};

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    
    quickSort(arr,0,7);

    cout<<"After Sorting: "<<endl;

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}