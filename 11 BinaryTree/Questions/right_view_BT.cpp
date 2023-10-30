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

void solve( node* root, vector<int> &ans, int lvl){

    //base case
    if( root == NULL){
        return ;
    }

    //we entered into new lvl
    if(lvl == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->right, ans, lvl+1);
    solve(root->left, ans, lvl+1);

}
vector<int> rightView(node* root){
    
    vector<int> ans;
    solve(root, ans, 0);
    return ans;

}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    LevelOrderTraversal(root);

    vector<int> right;
    right = rightView(root);

    for(int i:right){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}