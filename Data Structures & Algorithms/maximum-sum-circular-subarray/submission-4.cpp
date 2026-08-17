class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxx = nums[0], minn = nums[0], sum = 0;

        int curmax = 0;
        int curmin = 0;

        for(auto a:nums){
            curmin = min(a, curmin + a);
            curmax = max(a, curmax + a);
            maxx = max(maxx, curmax);
            minn = min(minn, curmin);
            sum += a;
        }
        cout<<maxx<<" "<<minn<<"\n";
        if(maxx < 0)
            return maxx;

        return max(sum-minn, maxx);

        
    }
};