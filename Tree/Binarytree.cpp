#include<bits/stdc++.h>
using namespace std;

// create node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// create node function
Node* createNewNode(int data){
    Node* newnode = new Node();
    if(!newnode){
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//Insert new node in tree; 
void insertnode(Node** root, int data){
    if(*root == NULL){
        *root = createNewNode(data);
        return ;
    }

    queue<Node*> q;
    q.push(*root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            temp->left = createNewNode(data);
            return ;
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = createNewNode(data);
            return ;
        }
    }
}


int main() {
   Node* root = NULL;
   int n,dt;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>dt;
      insertnode(&root,dt);
   }
   inorder(root);
   cout<<isbst(root);
   cout<<isBSt(root,INT_MIN,INT_MAX);
}