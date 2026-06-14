class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0, cnt = 1;
        if(nums.size() == 0) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[ptr] != nums[i]){
                nums[++ptr] = nums[i];
                cnt++;
            }
        }

        return cnt;
    }
};