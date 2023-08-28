#include<iostream>

using namespace std;

void merge(int arr[], int s, int e){
    
    int mid = s+(e-s)/2;

    //making sizes of two separate array
    int len1 = mid-s+1;
    int len2 = e-mid;

    //making two separate arrays
    int *first = new int [len1];
    int *second = new int [len2];

    int mainArrayIndex = s;

    //copying values to first array
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }

    //copying values to first array
    mainArrayIndex = mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

    //merge two sorted array code
    int index1 =0;
    int index2 =0;
    mainArrayIndex = s;

    while( index1<len1 && index2<len2 ){
        if( first[index1] < second[index2] ){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while( index1<len1 ){
        arr[mainArrayIndex++] = first[index1++];
    }
    while( index2<len2 ){
        arr[mainArrayIndex++] = second[index2++];
    }


    delete[] first;
    delete[] second;
}

void mergeSort(int arr[],int s, int e){
    
    //base case
    if(s>=e){
        return ;
    }

    int mid = s+(e-s)/2 ;

    //sort left part
    mergeSort(arr, s,mid-1);

    //sort right part
    mergeSort(arr,mid+1,e);

    //merge
    merge(arr,s,e);

}

int main(){

    int arr[8] = {4,8,6,1,5,7,3,2};

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    int n = 8;
    
    mergeSort(arr , 0 , n-1 );

    cout<<"After Sorting: "<<endl;

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}