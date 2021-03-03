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

Node* findN(Node* root, int d){
    if(root == NULL) return NULL;

    if(root->data == d){
        return root;
    }
    
    Node* lft = findN(root->left, d);
    Node* rgt = findN(root->right, d);

    return lft == NULL ? rgt : lft ;
}

int cntNode(Node* root){
    if(root == NULL) return 0;

    int lftcnt = cntNode(root->left);
    int rgtcnt = cntNode(root->right);

    return 1+lftcnt+rgtcnt ;
}

int Bigbang(Node* root, int x, int n){

    Node* t = findN(root,x);

    int lft = cntNode(t->left);
    int rgt = cntNode(t->right);
    int rem = n-lft-rgt-1;

    if(lft > rgt+rem) return 1;
    if(rgt > lft+rem) return 1;
    if(rem > lft+rgt) return 1;
    return 0;
}

int main() {
   Node* root = NULL;
   int n,dt,x;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>dt;
      insertnode(&root,dt);
   }
   cin>>x;
   cout<<Bigbang(root,x,n);
}