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

    int data;
    cout<<"Enter the data: "<<endl;
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

void inOrder(node* root){

    //base case
    if( root == NULL ){
        return;
    }

    //LNR
    inOrder(root->left);
    cout<< root -> data <<" ";
    inOrder(root->right);
    
}

void preOrder(node* root){

    //base case
    if( root == NULL ){
        return;
    }

    //LNR
    cout<< root -> data <<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void postOrder(node* root){

    //base case
    if( root == NULL ){
        return;
    }

    //LNR
    postOrder(root->left);
    postOrder(root->right);
    cout<< root -> data <<" ";
    
}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    cout<<"Inorder: ";
    inOrder(root);cout<<endl;

    cout<<"Preorder: ";
    preOrder(root);cout<<endl;

    cout<<"Postorder: ";
    postOrder(root);cout<<endl;

    return 0;
}