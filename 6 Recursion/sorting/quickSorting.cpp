#include<iostream>
using namespace std;

int partiton(int arr[], int s, int e){
    
    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1 ; i<=e ; i++){
        if(arr[i] <= pivot){ 
            cnt++;
        }
    }

    //swaping to right position
    int pivotIndex = s+cnt;
    swap(arr[pivotIndex],arr[s]);

    //sorting left and right part
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        
        while (arr[i]<arr[pivotIndex]){
            i++;
        }
        while (arr[j]>arr[pivotIndex]){
            j--;
        }

        if (i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int arr[],int s, int e){

    //base case
    if (s>=e){
        return ;
    }

    //partition process
    int p = partiton(arr,s,e);

    //recurive call
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){

    int arr[8] = {4,8,6,1,5,7,3,2};

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    quickSort(arr,0,7);

    cout<<"After Sorting: "<<endl;

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}