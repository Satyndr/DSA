#include<iostream>

using namespace std;

int main(){

    //initialisation of 2d array
    int box[3][3];

    //taking input
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>box[i][j];
        }
    }
    //i have changed this :)

    //printing 2d array
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<box[i][j];
        }
    }


    return 0;
}