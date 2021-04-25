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

bool ispath(Node* root,int cs,int sum){
    if(root == NULL) return false;

    if(root->left == NULL && root->right == NULL){
        if(sum == cs+root->data) return true;
        return false;
    }

    return ispath(root->left,cs+root->data,sum) || ispath(root->right,cs+root->data,sum);

}

int main() {
   Node* root = NULL;
   int n,dt;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>dt;
      insertnode(&root,dt);
   }
   int sum;
   cin>>sum;
   cout<<ispath(root,0,sum);
}