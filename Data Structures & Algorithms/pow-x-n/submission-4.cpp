class Solution {
public:
    double myPow(double x, int pow) {
        if(pow == 0) return 1;
        //if(x == 0) return 0;
        double output = 1;
        int n = abs(pow);
        while(n){
            if(n & 1)
                output *= x;
            x *= x;
            n >>= 1;
        }
        if(pow < 0) return static_cast<double>(1/output);
        return output;
    }
};
