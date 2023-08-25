#include<iostream>

using namespace std;

bool linearSearch(int arr[], int size, int key){

    if(size==0 ){
        return false;
    }

    if(arr[0]==key){
        return true;
    }
    else{
        return linearSearch(arr+1,size-1,key);
    }
    
}

int main(){

    int arr[5] = {1,4,7,3,9};

    if(linearSearch(arr,5,9)){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }

    return 0;
}