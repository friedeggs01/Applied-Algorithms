// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n){
    int ans;
    int lo = 1, hi = n;
    while(lo <= hi){
        int mid =lo + (hi - lo)/2;
        if(isBadVersion(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}