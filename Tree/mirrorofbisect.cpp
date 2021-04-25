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


//Insert new node in tree; 
void insertnode(Node** root, int data){
    if(*root == NULL){
        *root = new Node(data);
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
            temp->left =  new Node(data);
            return ;
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = new Node(data);
            return ;
        }
    }
}

bool ismirror(Node* lst,Node* rst){
    if(lst == NULL && rst == NULL) return true;
    else if(lst != NULL && rst == NULL) return false;
    else if(lst == NULL && rst != NULL) return false;
    else {
        if(lst->data == rst-> data){
           if(ismirror(lst->left,rst->right) &&
              ismirror(lst->right, rst->left)){
                  return true;
              }
        }
        return false;
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
   cout<<ismirror(root->left,root->right);
}