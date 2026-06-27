class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if(matrix.size() == 0) return {};
        int left=0, right = matrix[0].size()-1;
        int top = 0;
        int bot = matrix.size()-1;
        while(left < right && bot > top){
            for(int i=0; i< right-left; i++)
                output.push_back(matrix[top][left+i]);
            
            for(int i=0; i< bot-top; i++)
                output.push_back(matrix[top+i][right]);
            
            for(int i=0; i< right - left ; i++)
                output.push_back(matrix[bot][right-i]);

            for(int i=0;i< bot-top;i++)
                output.push_back(matrix[bot-i][left]);
            
            left++;
            right--;
            top++;
            bot--;
        }
        if(left == right && top == bot && matrix.size()%2) output.push_back(matrix[top][left]); 
        else if(left == right && matrix[0].size()%2) for(int i=top;i<=bot;i++) output.push_back(matrix[i][left]);
        else if(matrix.size()%2) for(int i = left;i<=right;i++) output.push_back(matrix[bot][i]);
        return output;
    }
};
