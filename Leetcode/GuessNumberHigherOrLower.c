/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int ans;
    int lo = 1, hi = n;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        int check = guess(mid);
        if(check == 0){
            return mid;
        } else if (check == 1){
            lo = mid +1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}