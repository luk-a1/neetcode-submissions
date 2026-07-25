class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(accumulate(nums.begin(), nums.end(), 0) < target) return 0;
        int mincnt =  nums.size();
        if( nums[0] >= target ) return 1;

        int l = 0;
        
        if(nums.size() < 2) return 0;

        int cnt=0;

        for(int i=0; i < nums.size(); i++){
            cnt += nums[i];

            while(cnt >= target){
                mincnt = min(mincnt, i-l+1);
                cnt -= nums[l++];
            }
        }

        return mincnt;
    }
};