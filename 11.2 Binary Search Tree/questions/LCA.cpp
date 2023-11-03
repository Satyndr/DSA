//least common ancestor
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

node *LCAinaBST(node *root, node *P, node *Q){

    //base case
    if( root == NULL){
        return NULL;
    }

    if( root->data < P->data && root->data < Q->data){
        return LCAinaBST(root->right, P, Q);
    }

    if( root->data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, Q);
    }

    else{
        return root;
    }
}

int main(){

    node* root = NULL;

    cout<<"Enter data to create BST: "<<endl;
    takeInput(root);
    //10 8 21 7 27 5 4 3 -1

    LevelOrderTraversal(root);

    node* p = root->left;
    node* q = root->right;

    cout<<"LCA: "<<LCAinaBST(root, p, q)->data<<endl;


    return 0;
}