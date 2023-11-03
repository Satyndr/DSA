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

node* findMin(node* root){

    node* temp = root;

    while (temp->left != NULL){
        temp = temp -> left;
    }
    return temp;

}

//deletion
node* deleteNode(node* root, int x){

    if( root == NULL){
        return root;
    }

    //base case
    if(root->data == x){
        //0 child
        if( root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left
        if( root->left != NULL && root->right == NULL ){
            node* temp = root -> left;
            delete root;
            return temp;
        }
        //right
        if( root->left == NULL && root->right != NULL ){
            node* temp = root -> right;
            delete root;
            return temp;
        }

        //2 child
        if( root->left != NULL && root->right != NULL ){
            int mini = findMin(root->right) -> data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }

    }

    else if( x < root->data){
        root->left = deleteNode(root->left, x);
        return root;
    }
    else {
        root->right = deleteNode(root->right, x);
        return root;
    }

}

int main(){

    node* root = NULL;

    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    //10 8 21 7 27 5 4 3 -1

    LevelOrderTraversal(root);

    cout<<endl;
    root = deleteNode(root, 3);
    LevelOrderTraversal(root);

    root = deleteNode(root, 5);
    LevelOrderTraversal(root);

    root = deleteNode(root, 8);
    LevelOrderTraversal(root);

    return 0;
}