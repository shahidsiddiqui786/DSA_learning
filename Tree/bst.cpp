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
Node* insertnode(Node* root, int data){
    if(root == NULL){
        root = createNewNode(data);
        return root;
    }
    int rootval = root->data;
    if(rootval < data){
        if(root->right != NULL){
           root->right = insertnode(root->right,data);
           return root;
        }
        else{
           root->right = createNewNode(data);
           return root;
        }
    }
    else{
        if(root->left != NULL){
            root->left = insertnode(root->left,data);
            return root;
        }
        else{
            root->left = createNewNode(data);
            return root;
        }
    } 
}

//print inorder
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
    

    inorder(temp->left);
     cout<<temp->data<<" ";
    inorder(temp->right);
     
}

//search the element in tree if it present or not.
bool search(Node* root, int ele){
    if(root == NULL){
        return false;
    }

    if(root->data == ele){
        return true;
    }
    else if(root->data < ele){
        return search(root->right, ele);
    }
    else{
        return search(root->left, ele);
    }
}

//search min and max element in a bst
//min fun()
int minfun(Node* root){
    if(root == NULL){
        cout<<"tree is empty";
        return 0;
    }

    if(root->left != NULL){
        return minfun(root->left);
    }
    else{
       return root->data;
    }
}

//max fun
int maxfun(Node* root){
    if(root == NULL){
        cout<<"tree is empty";
        return 0;
    }

    if(root->right != NULL){
        return maxfun(root->right);
    }
    else{
       return root->data;
    }
}

//height of tree
int height(Node* root){
    if(root == NULL){
        return -1;
    }
   int lefth = height(root->left);
   int righth = height(root->right);

    return max(lefth,righth)+1;
}

//level order traversal
void levelorder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->data<<" ";
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
        q.pop();
    }
}

//delete a ele from bst
Node* deletele(Node* root, int data){
    if(root == NULL) return root;

    if(root->data == data){
      //found
      //if it has 2 child
      if(root->left != NULL && root->right != NULL){
        int minp = minfun(root->right);
         root->data = minp;
         root->right = deletele(root->right, minp);
         return root;
      }
      //if it has 1 child
      else if(root->left != NULL || root->right != NULL){
         Node* temp = root; 
         if(root->left != NULL) root = root->left;
         if(root->right != NULL) root = root->right;
         delete temp;
         return root;
      }
      //if it has 0 child
      else{
          delete root;
          root = NULL;
          return root;
      }
    }
    else if(root->data > data){
        root->left = deletele(root->left, data);
        return root;
    }
    else if(root->data < data){
        root->right = deletele(root->right, data);
        return root;
    }
}



int main() {
   Node* root = NULL;
   int n,dt;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>dt;
      root = insertnode(root,dt);
   }
   inorder(root);
   int val;
   cout<<"enter val to search"<<'\n';
   cin>>val;
   cout<<search(root,val);
   cout<<"min of bst"<<minfun(root)<<'\n';
   cout<<"max of bst"<<maxfun(root)<<'\n';
   cout<<"height of bst"<<height(root)<<'\n';
   
   int del;
   cin>>del;
   root = deletele(root,del);
   levelorder(root);
}