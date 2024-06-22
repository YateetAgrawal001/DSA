#include<iostream>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int val;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this-> right = NULL;
    }
   
};
void display(Node * root){
    if(root == NULL) return ;
    cout<<root->val<<" ";
     display(root->left);
     display(root->right);
}
int sum(Node * root){
    if(root == NULL ) return 0;
    return root->val + sum ( root-> left ) + sum ( root -> right );
}
int size(Node * root){
    if(root == NULL ) return 0;
    return 1 + size ( root-> left ) + size ( root -> right );
}
int maxTree(Node * root){
    if(root == NULL) return INT_MIN;
    return max(root->val,max(maxTree(root->left),maxTree(root->right)));
}
int levels(Node * root){
    if(root == NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}
void height(Node * root){
  //levels - 1 is the height of the binary tree
}

int main(){
    Node* a = new Node(1);  //root node
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    display(a);
    cout<<endl;
    cout<<sum(a)<<endl;
    cout<<size(a)<<endl;
    cout<<maxTree(a)<<endl;
    cout<<levels(a)<<endl;
    cout<<height(a)<<endl;
    
}

/*
 int levels(TreeNode*root){
     if(root==NULL) return 0;
     return 1+max(levels(root->left),levels(root->right));
 }
 void nthlevel(TreeNode* root,int curr,int l,vector<int> &ans){
     
     if(root==NULL) return ;
     if(curr == l) {
         ans[l] = root->val;
         return;
     }
    
         nthlevel(root->left,curr+1,l,ans);
          nthlevel(root->right,curr+1,l,ans);
 }

 void levelOrder(TreeNode* root,vector<int> &ans){
     int n= levels(root);
     for(int i =0;i<n;i++){
         nthlevel(root,0,i,ans);
     }
 }

 */
