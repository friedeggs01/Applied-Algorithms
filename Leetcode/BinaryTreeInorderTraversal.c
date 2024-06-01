/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int i=0;
int arr[101];
void inorder(struct TreeNode* s){
    if(s != NULL){
        inorder(s->left);
        arr[i++] = s->val;
        inorder(s->right);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    inorder(root);
    int* ans = malloc(i*sizeof(int));
    for(int j=0; j<i; j++){
        ans[j] = arr[j];
    }
    *returnSize = i; // to assign the array's size
    i = 0;
    return ans;
}