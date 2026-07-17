class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> prev(n, 1e9); prev[0] = 0;
        for(int i{0}; i < grid.size(); ++i){
            vector<int> curr(n);
            for(int j{0}; j < n; ++j)
            {
                if(!j) {curr[0] = grid[i][0] + prev[0]; continue;}
                curr[j] = grid[i][j] + min(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return prev[n-1];
    }
};