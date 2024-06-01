//Ý tưởng là tính tổng từ 0 tới i, sum[i] - k mà ra sum đã tồn tại trước đó đồng nghĩa với việc có thể có chuỗi mà tổng bằng k 
int subarraySum(int* nums, int numsSize, int k){
    int i, j;
    int base = numsSize * 1000;
    int hashMap = calloc((2*base+1), sizeof(int));
    int prefix = 0;
    hashMap[base]++;
    int ans = 0;
    for(i = 0; i<numsSize; i++){
        prefix = prefix + nums[i];
        int remain = prefix - k;
        ans += hashMap[remain + base]; // nếu đã tồn tại tổng có giá trị remain trước đó thì biến đếm sẽ được cộng thêm 1
        hashMap[base + prefix]++;
    }
    free(hashMap);
    return ans;
}