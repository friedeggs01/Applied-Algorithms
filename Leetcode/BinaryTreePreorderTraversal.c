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
void preorder(struct TreeNode* s){
    if(s != NULL){
        arr[i++] = s->val;
        preorder(s->left);
        preorder(s->right);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    preorder(root);
    int* ans = malloc(i*sizeof(int));
    for(int j=0; j<i; j++){
        ans[j] = arr[j];
    }
    *returnSize = i; // to assign the array's size
    i = 0;
    return ans;
}