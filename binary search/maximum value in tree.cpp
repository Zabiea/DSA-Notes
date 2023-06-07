//recursive

int maximumValue(Node* root){
  if(root==NULL) return INT_MIN;
  
  return max(root->data,max(maximumValue(root->left),maximumValue(root->right)));
}
