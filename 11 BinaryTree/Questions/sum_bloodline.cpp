//sum of the longest bloodline of a tree
#include<bits/stdc++.h>

using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    node(int value){
        this -> data = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* treeBuilder(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>> data;
    root = new node(data);

    if (data == -1){ // we will give -1 input for the not creating child node
        return NULL;
    }

    cout<<"Enter the left of " << data << endl;
    root->left = treeBuilder(root->left);

    cout<<"Enter the right of " << data << endl;
    root->right = treeBuilder(root->right);

    return root;
}

void LevelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

            cout<<temp->data<<" ";

            if( temp->left){
                q.push(temp -> left);
            }
            if( temp->right){
                q.push(temp -> right);
            }
        }
    }
    
}

void solve(node* root, int len, int &maxlen, int sum, int &maxSum){

    //base case
    if(root == NULL){
        if( len > maxlen){
            maxlen =len;
            maxSum = sum;
        }
        else if( len == maxlen){
            maxSum = max(sum , maxSum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, len, maxlen, sum, maxSum);
    solve(root->right, len, maxlen, sum, maxSum);

}

int sumOfLongRootToLeafPath(node* root){

    int len = 0 , maxlen = 0;
    int sum = 0 , maxSum = INT_MIN;

    solve(root, len, maxlen, sum, maxSum);

    return maxSum;
}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    LevelOrderTraversal(root);

    int max = sumOfLongRootToLeafPath(root);
    cout<<"Max: "<<max<<endl;

    return 0;
}