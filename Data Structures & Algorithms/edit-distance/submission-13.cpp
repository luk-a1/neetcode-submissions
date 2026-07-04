class Solution {
public:

    int lcs(string& w1, string& w2){

        if(w1.size() == 0) return w2.size();
        if(w2.size() == 0) return w1.size();
        
        vector<int> prev(w1.size()+1);
        

        int i = 0;
        int j = 0;

        for(int i=0;i<=w1.size();i++) prev[w1.size()-i] = i;
        
        for(int i=w2.size()-1; i >= 0; i--){
            vector<int> curr(w1.size()+1);
            curr[w1.size()] = w2.size() - i;
            for(int j = w1.size()-1;j >= 0; j--){
                if(w1[j] == w2[i]) curr[j] = prev[j+1];
                else curr[j] = min(prev[j+1], min(prev[j], curr[j+1])) + 1;
            }

            prev = curr;
        }

        return prev[0];
    }
    int minDistance(string word1, string word2) {
        return lcs(word1, word2);
    }
};
