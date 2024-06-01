int findClosestNumber(int* nums, int numsSize){
    int ans = 100000000;
    for(int i = 0; i<numsSize; i++){
        int temp = abs(nums[i]);
        if(temp < abs(ans)){
            ans = nums[i];
        } else if(temp == abs(ans) && nums[i] > 0){
            ans = abs(ans);
        }
    }
    return ans;
}