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

int height(node* root)
{
    //base case
	if( root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = (max(left,right)+1);
    return ans;
}

// bool isBalanced(node* root){

//     //base case
//     if( root == NULL){
//         return true;
//     }

//     bool left = isBalanced(root->left);
//     bool right = isBalanced(root->right);
//     bool diff = abs( height(root->left) - height(root->right) ) <= 1;

//     if(diff){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

//optimized
pair<bool,int> isBalanced(node* root){

    //base case
    if( root == NULL){
        pair<bool,int>p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalanced(root->left);
    pair<bool,int> right = isBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs( left.second - right.second ) <= 1;

    pair<bool,int> ans ;
    ans.second = max(left.second , right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
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
    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 -1 -1

    LevelOrderTraversal(root);

    if(isBalanced(root).first){
        cout<<"Balanced Tree"<<endl;
    }
    else{
        cout<<"Not Balanced Tree"<<endl;
    }

    return 0;
}