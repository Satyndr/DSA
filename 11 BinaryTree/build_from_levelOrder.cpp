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

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

int main(){

    node* root = NULL;

    //creating a tree
    //root = treeBuilder(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 


    buildFromLevelOrder(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    LevelOrderTraversal(root);

    return 0;
}
