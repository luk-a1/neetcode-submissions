class Solution {
public:
    unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    void dfs(int i, string curr, string& digits, vector<string>& out){
        if(i==digits.length()) out.push_back(curr);

        for(int j=0;j<m[digits[i]].size();j++)
            dfs(i+1, curr+m[digits[i]][j], digits, out);
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> out;
        if(digits.size()!=0) 
            dfs(0, "", digits, out);

        return out;
    }
};
