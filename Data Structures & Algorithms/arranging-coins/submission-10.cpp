class Solution {
public:
    int arrangeCoins(int n) {
        long long k = n;
        long long l = 0, r = n;
        long long mid; long long output = 0;

        while(l <= r){
            mid = r - (r - l)/2;
            
            long long required = mid*(mid+1)/2;

            if( n > required ) {l = mid + 1; output = max(output, mid);}
            else if ( n < required ) r = mid - 1;
            else if(n == required) return mid;
        }

        return output;
    }
};

// 1 2 3 -> 3*4/2 = 6