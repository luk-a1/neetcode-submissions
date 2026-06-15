class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = s.size();

        for(int i=0;i<l/2;i++){
            char c = s[i];
            s[i] = s[l-i-1];
            s[l-i-1] = c;
        }
    }
};