#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    
    int size = nums.size();
    vector<int>psm(size+1);
    map<int,int>m;
    int sum =0;
    psm[0] = 0;
    int count =0;
    
    
    for(int i=0 ; i<size; i++){
        
        sum = sum + nums[i];
        int rem = sum%k; 
        if(rem<0) rem = rem + k;
        psm[i+1] = rem;
    }
    
    for(int i: psm)
        m[i]++;
    
    
    for(auto i: m)
        if(i.second >1) count = count + (i.second * (i.second -1))/2;
        
    return count;        
    
}