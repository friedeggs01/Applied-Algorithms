int maximumCount(int* nums, int numSize){
    int pos = 0, neg = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] > 0) pos++;
        else if(nums[i] < 0) neg++;
    }
    if(pos>neg) return pos;
    else return neg;
}