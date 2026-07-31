class Solution {
public:
    //this should be the lowerbound
    long long mySqrt(long long x) {
        if(x == 1) return 1;
        if(x==0) return 0;
        long long l = 2;
        long long r = x/2;
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