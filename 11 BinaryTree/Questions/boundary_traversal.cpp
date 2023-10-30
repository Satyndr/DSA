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

void traverseLeft( node* root, vector<int> &ans){

    //base case
    if( root == NULL || (root->left == NULL && root->right == NULL)){
        return ;
    }

    ans.push_back(root->data);
    if( root->left){
        traverseLeft(root->left, ans);
    }
    else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(node* root, vector<int> &ans){

    //base case
    if( root == NULL){
        return;
    }
    if( root->left== NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root, vector<int> &ans){

    //base case
    if( root == NULL || (root->left == NULL && root->right == NULL)){
        return ;
    }

    if(root->right){
        traverseRight(root->right, ans);
    }
    else{
        traverseRight(root->left, ans);
    }

    ans.push_back(root->data);

}

vector<int> boundaryTraversal(node* root){

    vector<int> ans;
    ans.push_back(root->data);

    //left part store
    traverseLeft(root->left, ans);  
    
    //leaf nodes
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

    //storing right part reversively
    traverseRight(root->right, ans);

}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    LevelOrderTraversal(root);

    vector<int> boundary;
    boundary = boundaryTraversal(root);

    for(int i:boundary){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}