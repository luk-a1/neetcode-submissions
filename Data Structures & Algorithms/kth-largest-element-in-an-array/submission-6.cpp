class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int pqsize = 0;
        for(int i=0;i<nums.size();i++){
            if(pqsize < k) pq.push(nums[i]), pqsize++;
            else pq.push(nums[i]), pq.pop();
        }
        int a;
        return pq.top();
        while(!pq.empty()){
            a = pq.top();
            pq.pop();
        }
        return a;
    }
};
