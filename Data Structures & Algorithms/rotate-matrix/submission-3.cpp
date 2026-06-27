class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix.size()-1;

        while(l < r){
            int top = l;
            int bot = r;

            for(int i=0;i < r-l; i++){
                //int save = matrix[l][i];
                swap(matrix[top][l+i], matrix[top+i][r]);
                swap(matrix[top][l+i], matrix[bot][r-i]);
                swap(matrix[top][l+i], matrix[bot-i][l]);
            }
            l++;
            r--;
        }
    }
};
