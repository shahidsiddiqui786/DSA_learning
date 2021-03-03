#include<bits/stdc++.h>
using namespace std;

// create node
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data = d;
            left = right = NULL;
        };
};

//prob
Node* createTree(vector<int> v,int st, int ed){
    if(st >= ed) return NULL;

    int mxp, mx = INT_MIN ;
    for(int i=st;i<ed;i++){
         if(mx < v[i]){
             mx = v[i];
             mxp = i;
         }
    }
    Node* t = new Node(v[mxp]);
    t->left = createTree(v,st,mxp);
    t->right = createTree(v,mxp+1,ed);
    
    return t;
}

void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int main() {
   Node* root = NULL;
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   root = createTree(v,0,n);
   inorder(root);
}