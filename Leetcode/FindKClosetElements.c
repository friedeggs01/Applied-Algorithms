/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    int lo = 0, hi = arrSize - 1;
    int l = abs(x - arr[0]);
    int h = abs(x-arr[arrSize-1]);
    *returnSize = k;
    while(arrSize != k){
        if(l>h){
            lo++;
            l = abs(x-arr[lo]);
        } else {
            hi--;
            hi = abs(x-arr[hi]);
        }
        arrSize--;
    }

    return arr+lo;
}