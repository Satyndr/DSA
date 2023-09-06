/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/


#include<iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string digits, string output, int index, string mapping[], vector<string>& ans){

    //base case
    if( index >= digits.length() ){
        ans.push_back(output);
        return ;
    }

    int number = digits[index] - '0';
    string letters = mapping[number];

    for(int i=0;i<letters.length();i++ ){
        output.push_back(letters[i]);
        solve(digits, output, index+1, mapping, ans);
        output.pop_back();
    } 
}

vector<string> letterCombinations(string digits) {
    
    vector<string> ans;
    if( digits.length()==0 ){
        return ans;
    }
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index = 0;
    string output = "";

    solve(digits, output, index, mapping, ans);

    return ans;
}

int main(){

    string number_dialed = "23";

    vector<string> word = letterCombinations(number_dialed);

    for(string i:word){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}