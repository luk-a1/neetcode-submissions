class Solution {
public:
    bool checkValidString(string s) {
        int maxx = 0;
        int minn = 0;
        for(auto a:s){
            if(a == '('){
                maxx++;
                minn++;
            }

            if(a == ')'){
                maxx--;
                minn--;
            }

            if(a == '*'){
                maxx++;
                minn--;
            }

            minn = max(minn, 0);
            if(maxx < 0) return false;
        }

        return (minn == 0);
    }
};
