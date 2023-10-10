#include<bits/stdc++.h>

using namespace std;

int celebrity( vector<vector<int>> M, int n ){

    stack<int> s;
    //push all elements
    for(int i=0;i<n;i++ ){
        s.push(i);
    }

    while( s.size() > 1){

        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        //check if a knows b or viceversa
        if( M[a][b] == 1){
            s.push(b);
        }
        else{
            s.push(a);
        }

    }

    //now verify the last element is celebrity or not

    int element = s.top();
	int countcol = 0;
	for(int i=0;i<n;i++ ){
		if( M[element][i] == 1 ){
			return -1;
		}
	}

	for(int i=0;i<n;i++ ){
		if( M[i][element] == 1 ){
			countcol++;
		}
	}

	if(countcol == n-1){
		return element;
	}
	else{
		return -1;
	}
    
}

int main(){

    int n = 3; //no of people
    vector<vector<int>> M = {{0,1,0},{0,0,0},{0,1,0}};

    int celebrityIndex = celebrity( M, n);

    cout<<celebrityIndex;

    return 0;
}