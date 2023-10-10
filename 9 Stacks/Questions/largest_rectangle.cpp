// #include<iostream>
// #include<vector>
// #include<stack>
#include<bits/stdc++.h>

using namespace std;

vector<int> nextSmall(vector<int> &arr, int n){
    
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1 ; i>=0 ;i--){

        int num = arr[i];
        while( s.top() != -1 && arr[s.top()] >= num ){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> prevSmall(vector<int> &arr, int n){
    
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=0;i<n;i++){

        int num = arr[i];
        while( s.top() != -1 && arr[s.top()] >= num ){
            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    vector<int> next = nextSmall(heights, n);
    vector<int> prev = prevSmall(heights, n);

    int area = INT_MIN;

    for(int i=0;i<n;i++ ){

        if(next[i] == -1){
            next[i] = n;
        }

        int maxWidth = next[i]-prev[i]-1 ;
        int newArea = heights[i]*maxWidth;
        area = max(area, newArea);
    }

    return area;
}

int main(){

    vector<int> heights = {2,1,5,6,2,3};

    int area = largestRectangleArea(heights);

    cout<<area;

    return 0;
}