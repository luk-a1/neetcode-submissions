class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptr = 0;
        for(int i=0;i<t.size();i++)
            if(t[i] == s[ptr]) ptr++;
        
        if(ptr == s.size()) return true;
        return false;
    }
};