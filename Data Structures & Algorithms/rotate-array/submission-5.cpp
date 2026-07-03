class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return;
        if(k >= n) k = k%n;
        int cnt = 0;
        for(int i{0}; cnt != n; i++){
            int j = i;
            int prev = nums[i];
            do
            {
                int temp = nums[j];
                nums[j] = prev;
                prev = temp;
                j = (k+j)%n;
                cout<<prev<<" "<<j<<"\n";
                cnt++;

            }
            while( j != i );
            nums[i] = prev;
            cout<<"\n";
        }
    }
};