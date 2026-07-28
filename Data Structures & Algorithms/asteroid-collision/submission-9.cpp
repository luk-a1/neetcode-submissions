class Solution {
private:
    bool sign(int a, int b){
        return a > 0 && b > 0;
    }

    bool same_sign(int a, int b){ return a < 0 && b < 0 || a > 0 && b > 0;}
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(auto a:asteroids){
            if(s.empty()) 
                s.push(a);
            else
            {
                int t = s.top();
                if( t < 0 && a > 0 || a < 0 && t < 0 || a > 0 && t > 0) {s.push(a); continue;}
                while(!s.empty() && abs(a) > abs(s.top()) && !same_sign(s.top(), a)) s.pop();
                if(s.empty() || same_sign(s.top(), a)) s.push(a);
                if(!s.empty() && abs(a) == abs(s.top()) && !same_sign(s.top(), a)) s.pop();
                
            }
            
        }

        vector<int> output;
        while(!s.empty()) {output.push_back(s.top()); s.pop();}
        reverse(output.begin(), output.end());
        return output;
    }
};