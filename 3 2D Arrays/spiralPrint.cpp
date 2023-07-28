#include<iostream>

using namespace std;

void printSpiral(int arr[][3],int row,int col){
    
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
        for(int i=endingCol ; total<count && i>=startingCol ; i--){
            cout<<arr[endingRow][i]<<" ";
            count++;
        }
        endingRow--;

        //starting col
        for(int i=endingRow ; total<count && i>=startingRow ; i--){
            cout<<arr[i][startingCol]<<" ";
            count++;
        }
        startingCol++;
        
    }
}

int main(){

    int arr1[3][3] = {{1,2,3},{8,9,4},{7,6,5}};

    printSpiral(arr1,3,3);

    return 0;
}