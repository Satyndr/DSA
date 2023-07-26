//Palindrome means reverse is equal 
//also must not be case sensitive

#include <iostream>
using namespace std;

//function for getting the length of a string
int getLength(char arr[]){
    int count =0;
    for(int i=0;arr[i]!='\0';i++){
        count++;
    }
    return count;
}

//function to make all lowercase
char lowerCase(char ch){
    if(ch >='a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//function for checking Palindrome
bool check_palindrome(char arr[], int n){

    int s= 0;
    int e = n-1;

    while(s<=e){
        if(lowerCase(arr[s]) != lowerCase(arr[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }

    return 1;

}


//__main__
int main(){
    
    char word[20]={"ASDfdsa"};

    int n = getLength(word);

    if (check_palindrome(word,n)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }

}