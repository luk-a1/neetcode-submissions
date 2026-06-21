class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1 || intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] == b[0] ? a[1]<b[1] : a[0]<b[0];
        });
        
        vector<int> curr = intervals[0];
        int cnt = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= curr[0] && intervals[i][0] < curr[1]){
                
                if(intervals[i][1] <= curr[1])
                    curr = intervals[i];
                
                cnt++;
            }
            else curr = intervals[i];
        }

        return cnt;
        

    }
};
