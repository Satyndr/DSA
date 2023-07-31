// Searching in an 2D array in which the rows are sorted and also the colums are sorted like:
// 1  4  7  11  15
// 2  5  8  12  19
// 3  6  9  16  22
// 10 13 14 17  24
// 18 21 23 26  30

#include<iostream>

using namespace std;

bool search(int arr[][5], int row, int col, int key){

    int rowIndex = 0;
    int colIndex = col-1;

    while( rowIndex < row && colIndex >= col ){
        int element = arr[rowIndex][colIndex];

        if(element == key){
            return 1;
        }
        else if(element < key){
            rowIndex++;
        }
        else{
            colIndex--;
        }
        return 0;
    }

}

int main(){

    int arr[5][5] = {1,4,7,11,15,2,5,8,12,19,3,6,9,16,22,10,13,14,17,24,18,21,23,26,30};

    if(search(arr,5,5,17)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}