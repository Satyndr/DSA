#include<iostream>

using namespace std;

int main(){

    int row;
    cout<<"Enter Row: ";
    cin>>row;

    int* col = new int[row];
    int** arr = new int*[row];

    for(int i=0;i<row;i++){
        cout<<"Enter the "<<i+1<<" Column Len: ";
        cin>>col[i];
        arr[i] = new int[col[i]];
    }
    //creation of jagged array is done

    //now taking input
    for(int i=0;i<row;i++){
        cout<<"Row "<<i+1<<" values: ";
        for(int j=0;j<col[i];j++){
            cin>>arr[i][j];
        }cout<<endl;
    }

    //now giving output
    for(int i=0;i<row;i++){
        cout<<"Row "<<i<<" values: ";
        for(int j=0;j<col[i];j++){
            cout<<arr[i][j];
        }cout<<endl;
    }

    return 0;
}