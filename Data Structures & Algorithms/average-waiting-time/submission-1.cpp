class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int curr = -1;
        int st = 0;
        long long sum = 0;
        for(int i=0;i<customers.size();i++)
        {
            st = max(curr, customers[i][0]);
            curr = st+customers[i][1];
            sum += (curr - customers[i][0]); 
        }

        return static_cast<double>(sum)/customers.size();
    }
};