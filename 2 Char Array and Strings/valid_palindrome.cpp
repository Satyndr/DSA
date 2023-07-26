//check valid palindrome string
//like " abc d ef edc ba"
#include <iostream>

using namespace std;

//to check alphabets and numbers
bool valid(char ch){
    if((ch>='a' && ch<='z' ) || (ch>='A'&&ch<='Z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}

//to convert into lowercase
char lowerCase(char ch){
    if((ch>='a' && ch<='z' ) || (ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//to check Palindrome
bool checkPalindrome(string str){
    int s= 0;
    int e = str.length()-1;

    while(s<=e){
        if((str[s]) != (str[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }

    return 1;

}

int main() {

    string str = "A man, a plan, a canal: Panama";//this is palindrome string

    string temp = "";

    //push alphabets and numbers to temp
    for(int i=0;i<str.length();i++){
        if(valid(str[i])){
            temp.push_back(str[i]);
        }
    }

    //convert to lowercase
    for(int i=0;i<temp.length();i++){
        temp[i]=lowerCase(temp[i]);        
    }

    //check if palindrome or not
    cout<< checkPalindrome(temp);

    
}