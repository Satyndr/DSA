#include<iostream>

using namespace std;

bool checkPalindrome(string name,int i,int j){

    //base case
    if(i>j){
        return true;
    }

    
    if(name[i] != name[j]){
        return false;
    }
    else{
        return checkPalindrome(name,i+1,j-1);
    }
}

int main(){

    string name = "rabbar";

    if(checkPalindrome(name,0,name.length()-1)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }

    return 0;
}