//the array is sorted
#include<iostream>

using namespace std;

bool binarySearch(int arr[][3] ,int row, int col, int key){
    
    int start=0;
    int end=(row*col)-1;
    int mid = start + (end-start)/2;

    while(start<=end){

        int element = arr[mid/col][mid%col];

        if(key==element){
            return 1;
        }
        else if(key<element){
            end=mid+1;
        }
        else{
            start=mid-1;
        }
        mid = start +(end-start)/2;
    }
    return 0;
}

int main(){

    int box[3][3] = {1,2,3,4,5,6,7,8,9};

    int key = 88;

    if (binarySearch(box,3,3,key)){
        cout<<"Found! "<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}