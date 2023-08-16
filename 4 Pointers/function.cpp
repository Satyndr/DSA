#include<iostream>

using namespace std;

int getSum(int *arr, int n){
    
    cout<<"Size : "<<sizeof(arr)<<endl;

    int sum =0;
    for(int i=0;i<n;i++){
        sum += i[arr];
    }
    return sum;
}



//passing part of array in the function
int main(){

    int arr[6] = {1,2,3,4,5,6};

    cout<<"Sum is: "<<getSum(arr+3,3)<<endl;

    return 0;
}