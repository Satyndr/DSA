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

pair<bool,int> sum_tree(node* root){

    if( root == NULL){
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }

    if( root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool,int> left = sum_tree(root->left);
    pair<bool,int> right = sum_tree(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool condn = left.second + right.second == root -> data;

    pair<bool,int> ans;
    if( leftAns && rightAns && condn){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }

    return ans;

}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    LevelOrderTraversal(root);

    if(sum_tree(root).first){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}