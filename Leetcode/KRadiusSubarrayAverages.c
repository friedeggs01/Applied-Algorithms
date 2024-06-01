/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize){
    int* ans = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int sum = 0;
    if(numsSize < 2*k+1){
        for(int i=0; i<numsSize; i++){
            ans[i] = -1;
        }
        return ans;
    }
    for(int i=0; i<k; i++){
        ans[i] = -1;
        sum += nums[i];
    }
    sum += nums[k];
    for(int i=k+1; i<2*k+1; i++){ 
        sum += nums[i];            
    }
    ans[k] = sum/(2*k+1);
    for(int i=k+1; i<numsSize-k; i++){
        sum += nums[i+k] - nums[i-k-1];
        ans[i] = sum/(2*k+1);
    }
    for(int i = 0; i < k; i++){
        ans[numsSize-1-i] = -1;
    }
    return ans;
}