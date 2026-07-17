class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0); prev[0] = 1;
        

        for(int i=0;i<obstacleGrid.size();i++)
        {
            vector<int> curr(n);
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1) {curr[j] = 0; continue;}
                if(j == 0) {curr[j] = prev[j]; continue;}
                int top = prev[j];
                int left = curr[j-1];
                curr[j] = top + left;
                cout<<curr[j]<<" ";
            }
            cout<<"\n";
            prev = curr;
        }

        return prev[n-1];

    }
};