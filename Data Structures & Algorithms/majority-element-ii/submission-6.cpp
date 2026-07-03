class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        if(nums.size() == 1 || (nums.size() == 2 && nums[0] != nums[1])) return nums;
        if(nums.size() == 2 && nums[0] == nums[1]) return {nums[0]}; 
        int num1 = -1;
        int num2 = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1){
                cnt1++;
                //cnt2--;
            }
            else if(nums[i] == num2){
                //cnt1--;
                cnt2++;
            }
            else if(cnt1 == 0) { num1 = nums[i]; cnt1 = 1; }
            else if(cnt2 == 0) { num2 = nums[i]; cnt2 = 1; }
            else {cnt1--; cnt2--;}
        }
        
        cnt1 = 0; cnt2 = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1) cnt1++;
            if(nums[i] == num2) cnt2++;
        }
        vector<int> output;
        int n = nums.size();
        if(cnt1 > n/3 ) output.push_back(num1);
        if(cnt2 > n/3 && cnt1 > n/3 && num1 != num2) output.push_back(num2);
        return output;
            
    }
};