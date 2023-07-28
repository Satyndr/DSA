#include<iostream>

using namespace std;

void printWave(int arr[][3],int row, int col){
    
    for(int i=0;i<row;i++){
        if(i%2==0 || i==0){
            for(int j=0;j<row;j++){
                cout<<arr[j][i];
            }
        }
        else{
            for(int j=row-1;j>=0;j--){
                cout<<arr[j][i];
            }
        }
        cout<<endl;
    }

}

int main(){

    int box1[3][3] = {1,2,3,4,5,6,7,8,9};

    printWave(box1,3,3);

    return 0;
}