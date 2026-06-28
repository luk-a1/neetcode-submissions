class Solution {
public:
    bool isPalindrom(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) 
                return false;
            i++;
            j--;
        }

        return true;
    }

    void dfs(string s, int start, vector<vector<string>>& out, vector<string> curr){
        if(start == s.length()) {out.push_back(curr); return;}
        for(int i = start; i<s.length(); i++)
            if(isPalindrom(s, start, i)){
                curr.push_back(s.substr(start, i-start+1));
                dfs(s, i+1, out, curr);
                curr.pop_back();
            }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> curr;
        dfs(s, 0, output, curr);
        return output;
    }
};
