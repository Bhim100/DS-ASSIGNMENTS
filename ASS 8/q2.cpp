#include <bits/stdc++.h>
using namespace std;

class Treenode {
public:
    int data;
    Treenode* left;
    Treenode* right;

    Treenode(int d) {
        data = d;
        left = right = nullptr;
    }
};

void searchrec(Treenode *root,int x){
    if (root == nullptr) {
        cout << x << " not found"<<endl;
        return;
    }
    if (root->data==x){
    cout<<"found "<<x<<endl;
    return;
    }
    if(x > root->data){
        searchrec(root->right,x);
    }
    else{  
        searchrec(root->left,x);
    }
    

}

void searchit(Treenode *root,int x){
    
    while(root){
    if (root->data==x){

    cout<<"found "<<x<<endl;
    return;
    }
   
    if (x > root->data)
        root = root->right;  
    else
        root = root->left;    
    }

    cout << x << " not found"<<endl;
    return;
}
    
int max(Treenode *root){
    if(!root) return -1 ;
        
    while(root->right){
        
      root=root->right;
}
return root->data;
}

int min(Treenode *root){
    if(!root) return -1 ;
        
    while(root->left){
        
      root=root->left;
}
return root->data;
}

Treenode* inorderSuccessor(Treenode* root, Treenode* x) {
    Treenode* succ = nullptr;

    while (root != nullptr) {
        if (x->data < root->data) {
            succ = root;           
            root = root->left;     
        }
        else {
            root = root->right;   
        }
    }

    return succ;
}


Treenode* inorderPredecessor(Treenode* root, Treenode* x) {
    Treenode* pred = nullptr;

    while (root != nullptr) {
        if (x->data > root->data) {
            pred = root;           
            root = root->right;    
        } 
        else {
            root = root->left;     
               }
    }

    return pred;
}


