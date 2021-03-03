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
//problem:- given a binary tree and a number find how many
 // subtree are there with given sum of nodes value == given no.

int sumsubtree(Node* root){
    if(root == NULL) return 0;
    
    int ls = sumsubtree(root->left);
    int rs = sumsubtree(root->right);

    return (root->data + rs + ls);
}

int noofSt(Node* root , int sum){
    if(root == NULL){
        return 0;
    }

    if(sumsubtree(root) == sum){
       return 1 + noofSt(root->left,sum) + noofSt(root->right,sum);
    }
    return noofSt(root->left,sum) + noofSt(root->right,sum);
}

//print inorder
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}


int main() {
   Node* root = NULL;
   int n,dt;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>dt;
      insertnode(&root,dt);
   }
   cout<<"Enter amount\n";
   int sum;
   cin>>sum;
   cout<<noofSt(root,sum);
}


// method two of binary tree .
/*
class Node{
    public:
        int data;
        Node* left,*right;
        left = right = NULL;
        Node(int d){
            data = d;
            left = right = NULL;
        }
}

Node* createTree(vector<int> v){
     if(v.size() == 0) return NULL;

     int no = v[0];
     Node* root = new Node(no);
     int i = 1;
     queue<Node*> q;
     q.push(root);

     while(!q.empty() && i<v,size()){
         Node* temp = q.front();
         q.pop();
         no = v[i++];
         temp->left = new Node(no);
         q.push(temp->left);
         if(i>=v.size()){
             break;
         }
         no = v[i++];
         temp->right = new Node(no);
         q.push(temp->right);
     }
}
*/