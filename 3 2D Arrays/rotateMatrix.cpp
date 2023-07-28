#include<iostream>

using namespace std;

void rotateMatrix(int a [][4],int N, int M){

    for(int i=0;i<N/2;i++){
        for(int j=i;j<(M-1-i);j++){
            
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][M - 1 - j];
            a[N - 1 - i][M - 1 - j] = a[j][M - 1 - i];
            a[j][M - 1 - i] = temp;
        }
    }
    
}

void printMatrix(int arr[][4],int row, int col){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){

    int matrix[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printMatrix(matrix,4,4);
    cout<<endl;
    
    rotateMatrix(matrix,4,4);

    printMatrix(matrix,4,4);

    return 0;
}