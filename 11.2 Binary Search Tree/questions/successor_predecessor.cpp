#include<bits/stdc++.h>

using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

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

node* insert(node* root, int value){

    //base case
    if(root == NULL){
        root = new node(value);
        return root;
    }

    if( value > root->data ){
        root->right = insert(root->right, value);
    }

    if( value < root-> data){
        root->left = insert(root->left, value);
    }

    return root;
}

void takeInput(node* &root){

    int value;
    cin>>value;

    while(value != -1){
        root = insert(root, value);
        cin>>value;
    }

}

pair<int, int> predecessorSuccessor(node *root, int key){
    
    //find key
    node* temp = root;
    int suc = -1;
    int pre = -1;

    while( temp->data != key){

        if( key > temp-> data ){
            pre = temp->data;
            temp = temp -> right;
        }
        else{
            suc = temp -> data;
            temp = temp -> left;
        }

    }

    //pre
    node* leftTree = temp->left;
    while( leftTree != NULL){
        pre = leftTree -> data;
        leftTree = leftTree->right;
    }

    //suc
    node* rightTree = temp->right;
    while( rightTree != NULL){
        suc = rightTree -> data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pre, suc);
    return ans;

}

int main(){

    node* root = NULL;

    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    //10 8 21 7 27 5 4 3 -1

    LevelOrderTraversal(root);

    cout<<"1: "<<predecessorSuccessor(root, 7).first<<endl;  
    cout<<"2: "<<predecessorSuccessor(root, 7).second<<endl;  

    return 0;
}