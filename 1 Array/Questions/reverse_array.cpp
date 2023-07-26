//reverse array after nth index
#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v,int n){

    int s= n+1, e=v.size()-1;

    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }

}

vector<int> printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout<<"Before Reverse: ";
    printVector(v);

    vector<int> ans = reverse(v,1);

    cout<<"After reverse: ";
    printVector(ans);

    return 0;

}