#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int max_product_i = nums[0];
    int min_product_i = nums[0];
    int temp;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] < 0) {
            swap(max_product_i, min_product_i);
        }
        max_product_i = max(max_product_i*nums[i], nums[i]);
        min_product_i = min(min_product_i*nums[i], nums[i]);
        ans = max(ans, max_product_i);
    }
    return ans;    
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    vector<int> v{2,-3,-4};
    cout << maxProduct(v);
}