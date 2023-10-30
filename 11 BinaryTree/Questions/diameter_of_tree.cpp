//diameter of tree is the longest length betwwn two any ending node
#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* treeBuilder(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = treeBuilder(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = treeBuilder(root->right);
    return root;

}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

pair<int,int> fastDiameter(node* root){

    //base case
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = fastDiameter(root->left);
    pair<int,int> right = fastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second +1 ;

    pair<int,int> ans;
    ans.first = max( op1 , max( op2, op3));
    ans.second = max(left.second , right.second) +1;

    return ans;
}

int diameterOfBinaryTree(node* root){
    
    return fastDiameter(root).first;
}

int main(){

    node* root = NULL;

    //creating a tree
    root = treeBuilder(root);

    //1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1 -1

    levelOrderTraversal(root);

    cout<<"diameterOfBinaryTree : "<<diameterOfBinaryTree(root)<<endl;

    return 0;
}