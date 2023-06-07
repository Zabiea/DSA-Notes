

//recursive

int size(Node* root){
  if(root==NULL) return 0;
  
  return size(root->right)+size(root->left)+1;
  
}
