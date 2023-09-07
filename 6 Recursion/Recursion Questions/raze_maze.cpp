// rat maze question
//return all the ways to travel the path  

#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>& maze, vector<vector<int>> visitor, int x,int y,int n){

    if((x>=0 && x<n) && (y>=0&&y<n) && (visitor[x][y] == 0) && (maze[x][y]==1)){
        return true;
    }
    else{
        return false;
    }

}

void solve(vector<vector<int>>& maze, int size, vector<vector<int>> visitor, int x, int y, string path, vector<string>& ans){

    //base case
    if(x==size-1 && y==size-1){
        ans.push_back(path);
        return;
    }

    visitor[x][y] = 1;

    //for going down
    int newx = x+1;
    int newy = y;
    if (isSafe( maze, visitor, x,y, size)){
        path.push_back('D');
        solve(maze, size, visitor, newx, newy, path, ans);
        path.pop_back();
    }

    //for going left
    newx = x;
    newy = y-1;
    if (isSafe( maze, visitor, x,y, size)){
        path.push_back('L');
        solve(maze, size, visitor, newx, newy, path, ans);
        path.pop_back();
    }

    //for going up
    newx = x-1;
    newy = y;
    if (isSafe( maze, visitor, x,y, size)){
        path.push_back('U');        
        solve(maze, size, visitor, newx, newy, path, ans);
        path.pop_back();
    }

    //for going right
    newx = x;
    newy = y+1;
    if (isSafe( maze, visitor, x,y, size)){
        path.push_back('R');
        solve(maze, size, visitor, newx, newy, path, ans);
        path.pop_back();
    }

    visitor[x][y] = 0;


}

vector<string> pathFinder(vector<vector<int>>& maze, int size){

    vector<string> ans;

    if(maze[0][0] == 0){
        return ans;
    }

    //source index
    int srcx = 0;
    int srcy = 0;

    //initialised visitor vector with all values 0
    vector<vector<int>> visitor = maze;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            visitor[i][j]=0;
        }
    }

    string path = "";
    solve(maze, size, visitor, srcx, srcy, path, ans);
    sort(ans.begin(),ans.end());

    return ans;

}

int main(){

    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};  

    vector<string> path ;

    int size=4;

    path = pathFinder(maze, size);

    for(string i:path){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}