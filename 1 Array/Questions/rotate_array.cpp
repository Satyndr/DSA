//rotate the elements of array to kth position
#include <iostream>
#include <vector>

using namespace std;

vector<int> rotateVector(vector<int> &vect, int k){

    vector<int> temp(vect.size());
    for(int i=0;i<vect.size();i++){
        temp[(i+k)%vect.size()] = vect[i];        
    }
    vect = temp;
}

vector<int> printVector(vector<int> vect, int size){
    for(int i=0;i<size;i++){
        cout<<vect[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> vect1{1,2,3,4,5,6} ;

    rotateVector(vect1, 2);//rotate the value of vector by 3
    
    cout<<"After rotating: ";

    printVector(vect1,6);

}