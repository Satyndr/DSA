#include<iostream>

using namespace std;

void reverse(string& name, int i,int j){

    //base case
    if(i>j){
        return ;
    }

    //process
    swap(name[i],name[j]);
    i++, j--;

    //recursive call
    return reverse(name,i,j);
        
}

int main(){

    string name = "satendra";
    reverse(name,0,name.length()-1);
    
    cout<<name;

    return 0;
}