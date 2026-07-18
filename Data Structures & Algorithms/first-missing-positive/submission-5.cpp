class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size();i++)
            nums[i] = max(nums[i], 0);

        for(int i=0;i<nums.size();i++)
        {
            int k = abs(nums[i]);
            if(k == 0) nums[i] = nums.size()+1;
            else if(k > nums.size()) continue;
            else nums[k-1] = nums[k-1] < 0 ? nums[k-1] : nums[k-1] * -1;
        }
        int cnt = 1;
        for(auto a:nums) cout<<a<<" ";
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) cnt++;
            else break;
        }

        return cnt;
    }
};