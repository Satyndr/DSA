/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/

#include<iostream>
#include <vector>

using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans){

    //base case
    if(index>= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=index ; i<nums.size() ; i++){
        swap(nums[index],nums[i]);
        solve(nums, index+1, ans);
        swap(nums[index],nums[i]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);

    return ans;        
}


int main(){

    vector<int> arr = {1,2,3};

    vector<vector<int>> permutations = permute(arr);

    for(vector<int> i:permutations){
        for(int j:i){
            cout<<j<<" ";
        }cout<<endl;
    }

    return 0;

}