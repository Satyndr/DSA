#include<iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmaller(vector<int> &arr, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for(int i=n-1 ; i>=0 ;i--){

        int num = arr[i];
        while( s.top() >= num ){
            s.pop();
        }

        ans[i] = s.top();

        s.push(num);
    }

    return ans;
}

int main(){

    vector<int> v = {3,4,2,8};

    vector<int> ans = nextSmaller(v, 4);

    for(int i:ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}