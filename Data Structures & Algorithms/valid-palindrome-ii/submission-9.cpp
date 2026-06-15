class Solution {
public:

    bool solve(int l, int r, string& s, bool first){
        if(l>=r) return true;
        if(s[l] == s[r]) return solve(l+1, r-1, s, first);
        else if(first) return solve(l+1, r, s, false) || solve(l, r-1, s, false);
        else return false;
    }

    bool validPalindrome(string s) {
        return solve(0, s.length()-1, s, true);
    }
};