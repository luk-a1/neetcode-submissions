class Solution {
public:
    //this should be the lowerbound
    long long mySqrt(long long x) {
        long long l = 0;
        long long r = x;
        long long mid, out;
        while(l <= r){
            mid = r-(r-l)/2;

            if(mid*mid > x){
                r = mid-1;
                continue;
            }
            else if(mid*mid == x) return mid;
            else {l = mid+1; out = mid;}
        }

        return out;
    }
};