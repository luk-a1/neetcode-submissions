class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return 0;
        int currmax = nums[0];
        int i=0;
        int cnt=0;
        if(currmax >= nums.size()-1) return 1;
        int pos_of_max = i;
        while(i < currmax){
            
            
            for(int j=i;j<=currmax;j++)
                if(pos_of_max + nums[pos_of_max] < j + nums[j])
                    pos_of_max = j;
            
            cnt++;
            currmax = pos_of_max + nums[pos_of_max];
            i = pos_of_max;

            if(currmax >= nums.size()-1) break;
        }

        return cnt+1;

    }
};
