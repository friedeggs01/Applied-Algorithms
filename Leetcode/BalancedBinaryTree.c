/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getdepth(struct TreeNode *root){
    if(root == NULL) return 0;
    return fmax(1+getdepth(root->left), 1+getdepth(root->right)); 
}
bool isBalanced(struct TreeNode *root){
    if(root == NULL) return true;
    return (abs(getdepth(root->left) - getdepth(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right));
} 