/*
Given an string nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [a,b,c]
Output: [[],[a],[b],[a,b],[c],[a,c],[b,c],[a,b,c]]
*/

#include<iostream>
#include <vector>
#include<string>

using namespace std;


void solve(string& str, string output, int index, vector<string> &ans){

    //base case
    if(index >= str.length()){
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(str, output, index+1, ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);

}

vector<string> subsequences (string& str) {
    
    vector<string> ans;
    string output = "";
    int index = 0;
    solve( str, output, index, ans);

    return ans;
}



int main(){

    string arr = {1,2,3};
    vector<string> powersets;

    powersets = subsequences(arr);
    
    for (string i:powersets){
        cout << i << " ";   
    }cout << endl;

    return 0;
}