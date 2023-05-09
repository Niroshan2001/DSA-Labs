#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root==NULL){
        return;
    }
    traverseInOrder(root->left);
    cout<<root->key<<" ";
    traverseInOrder(root->right);

}

//create a node
struct node* createNode(int key){
  struct node* newnode=new node();
  newnode->key=key;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node==NULL){
    node=createNode(key);
  }
  else if(node->key>=key){
      node->left=insertNode(node->left,key);
  }
  else{
    node->right=insertNode(node->right,key);
  }
  return node;
  
}
node*  Mini(node* rootptr){

    if(rootptr->left==NULL){
        return rootptr;
    }
    return Mini(rootptr->left);
}
// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root==NULL){
      return root;
    }
    else if(root->key==key){
    if(root->left==NULL && root->right==NULL){
            
            root=NULL;
            
    }
    else if(root->left==NULL){
      root=root->right;
    }
    else if(root->right==NULL){
      root=root->left;
    }
    else{
      node* mini=Mini(root->right);
      root->key=mini->key;
      root->right=deleteNode(root->right,mini->key);
    }
    }
    else if(root->key<=key){
      root->right=deleteNode(root->right,key);
    }
    else{
      root->left=deleteNode(root->left,key);
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}