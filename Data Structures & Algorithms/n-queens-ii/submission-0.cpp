class Solution {
public:

    void solve(int x, set<int>& col, set<int>& posd, set<int>& negd, int& cnt, int& n){
        
        if(x == n){
            ++cnt;
            return;
        }
        
        for(int i=0;i<n;++i){
            int positive_diagonal = i+x;
            int negative_diagonal = i-x;
            int col_ = i;
            
            if(col.find(col_) != col.end()){
                continue;
            } 

            if(posd.find(positive_diagonal) != posd.end()){
                continue;
            }

            if(negd.find(negative_diagonal) != negd.end()){
                continue;
            }

            col.insert(col_);
            posd.insert(positive_diagonal);
            negd.insert(negative_diagonal);

            solve(x+1, col, posd, negd, cnt, n);

            col.erase(col_);
            posd.erase(positive_diagonal);
            negd.erase(negative_diagonal);

        }
    }
    int totalNQueens(int n) {
        set<int> posd;
        set<int> negd;
        set<int> col;
        int cnt = 0;

        solve(0, col, posd, negd, cnt, n);

        return cnt;
    }
};