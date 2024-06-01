/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static void traverse(struct TreeNode* root, int** result, int* retcol, int level){
    if(root == NULL) return;

    result[level][retcol[level]++] = root->val;
    traverse(root->left, result, retcol, level+1);
    traverse(root->right, result, retcol, level+1);
}
// maxdepth is a pointer point to value of tree's depth
static void getdepth(int *maxdepth, int currentdepth, struct TreeNode* root){
    if(*maxdepth < currentdepth) *maxdepth = currentdepth;
    if(root == NULL) return;
    getdepth(maxdepth, currentdepth+1, root->left);
    getdepth(maxdepth, currentdepth+1, root->right);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    // returnSize == maxdepth
    getdepth(returnSize, 0, root);
    int **result = (int**)malloc((*returnSize)*sizeof(int*));
    for(int i=0; i<*returnSize; i++){
        result[i] = (int*)malloc(1024*sizeof(int));
    }
    // Sizes at each level
    *returnColumnSizes = (int*)calloc((*returnSize), sizeof(int*));
    traverse(root, result, *returnColumnSizes, 0);
    return result;
}