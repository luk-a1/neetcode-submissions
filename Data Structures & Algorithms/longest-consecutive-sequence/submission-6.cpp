class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        if(nums.size() == 0) return 0;
        m[nums[0]] = 1;
        int maxx = 1;
        for(int i=1;i<nums.size();i++){
            if(m[nums[i]]) continue;
            int length = m[nums[i]+1] + m[nums[i]-1] + 1;
            m[nums[i]] = length;
            m[nums[i] + m[nums[i]+1]] = length;
            m[nums[i] - m[nums[i]-1]] = length;
            maxx = max(maxx, length);
        }

        return maxx;
    }
};
