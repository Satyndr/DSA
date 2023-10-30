#include<bits/stdc++.h>

using namespace std;

vector<int> reverseKgroup(vector<int> v,int n, int k){

    deque<int> d;
    vector<int> ans;

    //process first window of k sized
    for(int i=0;i<k;i++){
        if(v[i]<0){
            d.push_back(i);
        }
    }    

    //store answer of first k sized window
    if(d.size()>0){
        ans.push_back(v[d.front()]);
    }
    else{
        ans.push_back(0);
    }

    //process for remaining window
    for(int i=k; i<n ; i++){
        //removal

        if(!d.empty() && i-d.front() >= k){
            d.pop_front();
        }

        //addition
        if(v[i] < 0){
            d.push_back(i);
        }

        //ans store
        if(d.size()>0){
        ans.push_back(v[d.front()]);
        }
        else{
            ans.push_back(0);
        }

    }

    return ans;

}

int main(){

    vector<int> v = {4,6,2,7,3,8};

    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> ans;
    ans = reverseKgroup(v, 6, 2);

    for(int i:ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}