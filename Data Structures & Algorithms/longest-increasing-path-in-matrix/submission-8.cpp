class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& m, vector<vector<int>>& dp, vector<vector<bool>>& visited){
        if(visited[i][j]) return dp[i][j];
        visited[i][j] = true;
        int down=0, up=0, right=0, left=0;
        if(i+1 < m.size() && m[i][j] < m[i+1][j])  down = 1 + dfs(i+1, j,  m, dp, visited);
        if(i-1 >= 0 && m[i][j] < m[i-1][j])  up = 1+dfs(i-1, j, m, dp, visited);
        if(j+1 < m[0].size() && m[i][j] < m[i][j+1])  right = 1 + dfs(i, j+1, m, dp, visited);
        if(j-1 >= 0 && m[i][j] < m[i][j-1])  left = 1+dfs(i, j-1, m, dp, visited);

        dp[i][j] = max(dp[i][j], max(up, max(down, max(left, right))));
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int out = -1;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(!visited[i][j])
                    out = max(out, dfs(i, j, matrix, dp, visited));

        return out;
    }
};
