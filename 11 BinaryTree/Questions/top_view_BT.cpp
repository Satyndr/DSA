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

vector<int> topView(node* root){

    vector<int> ans;

    if( root == NULL){
        return ans;
    }

    map<int,int> topNode;
    queue<pair<node*, int> > q;

    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        //
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode -> data;

        if(frontNode->left)
            q.push(make_pair(frontNode->left, hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right, hd+1));

    }

    for(auto i: topNode){
        ans.push_back(i.second);
    }

    return ans;

}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    LevelOrderTraversal(root);

    vector<int> top;
    top = topView(root);

    for(int i:top){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}