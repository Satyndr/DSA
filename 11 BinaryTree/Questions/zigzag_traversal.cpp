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

vector<int> zigzagTraversal(node* root){

    vector<int> result;
    if( root == NULL){
        return result;
    }
    
    queue<node* > q;
    q.push(root);

    bool leftToRight = true;
    while(!q.empty()){

        int size = q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){

            node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1 ;
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }

        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;

}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    LevelOrderTraversal(root);

    vector<int> zigzag;
    zigzag = zigzagTraversal(root);

    for(int i:zigzag){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}