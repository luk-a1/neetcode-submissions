class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<bool> prev(s1.size()+1, false);
        prev[0] = true;
        if(s1.size() + s2.size() != s3.size()) return false;

        for(int i=1;i<s1.size()+1;i++)
            if(s1[i-1] == s3[i-1]) 
                prev[i] = prev[i-1];

        for(int i=0;i < s2.size(); ++i){
            vector<bool> curr(s1.size()+1, false);

            for(int j = 0; j < s1.size()+1; ++j){
                if(j == 0){
                    if(s2[i] == s3[i])
                        curr[0] = prev[0];
                }
                else{
                    if(s3[i+j] == s2[i]) curr[j] = curr[j] || prev[j];
                    if(s3[i+j] == s1[j-1]) curr[j] = curr[j] || curr[j-1];
                }
            }
            prev = curr;
        }

        return prev[s1.size()];
    }
};
