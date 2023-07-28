#include<iostream>

using namespace std;

void printSpiral(int arr[][4],int row,int col){
    
    //indexes
    int startingRow = 0;
    int endingCol=col-1;
    int endingRow=row-1;
    int startingCol=0;

    int count= 0;
    int total=row*col;

    while(count<total){

        //startingrow
        for(int i=startingCol; count<total && i<=endingCol; i++){
            cout<<arr[startingRow][i]<<" ";
            count++;
        }
        startingRow++;

        //ending Col
        for(int i=startingRow; count<total && i<=endingRow ;i++){
            cout<<arr[i][endingCol]<<" ";
            count++;
        }
        endingCol--;

        //endingRow
        for(int i=endingCol ; count<total && i>=startingCol ; i--){
            cout<<arr[endingRow][i]<<" ";
            count++;
        }
        endingRow--;

        //starting col
        for(int i=endingRow ; count<total && i>=startingRow ; i--){
            cout<<arr[i][startingCol]<<" ";
            count++;
        }
        startingCol++;
        
    }
}

int main(){

    int arr1[4][4] = {1,2,3,4,12,13,14,5,11,16,15,6,10,9,8,7};

    printSpiral(arr1,4,4);

    return 0;
}