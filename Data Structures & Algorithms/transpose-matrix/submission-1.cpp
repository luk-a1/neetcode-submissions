class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> output;
        if(n == m){
            for(int i=0;i<n;i++){
                for(int j = 0; j < n && j < i; ++j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            output = matrix;
        }

        else{
            output.assign(m, vector<int>(n,0));

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    output[i][j] = matrix[j][i];
                }
            }
        }
        return output;
    }
};