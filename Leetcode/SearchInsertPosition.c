int searchInsert(int* nums, int numsSize, int target){
    int lo=0, hi = numsSize - 1;
    while(lo <= hi){
    int mid = (lo + hi)/2;
    if(target < nums[mid]) hi = mid - 1;
    else if(target > nums[mid]) lo = mid + 1;
    else return mid;
    }
    return lo;
}