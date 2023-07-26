#include<iostream>

using namespace std;

bool isPresent(int arr[][4],int key,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==key){
                return 1;
            }
        }
    }

    return 0;
}

int rowSum(int arr[][4],int row,int col){
    
    for(int i=0;i<row;i++){
        int sum =0;
        for(int j=0;j<col;j++){
            sum = sum + arr[i][j];
        }
        cout<<"Row sum : "<<sum<<endl;
    }
}

int main(){

    //initialisation of 2d array
    int box[3][3];
    int box2[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    //taking input

    //printing 2d array
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<box2[i][j]<<" ";
        }
        cout<<endl;
    }

    int key =4 ;

    if (isPresent(box2,key,3,4)){
        cout<<"found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    rowSum(box2,3,4);


    return 0;
}