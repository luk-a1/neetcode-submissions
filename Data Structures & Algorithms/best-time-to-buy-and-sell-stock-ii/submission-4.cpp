class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int sum = 0;
        while(right < prices.size())
        {
            while(right < prices.size() && prices[left] >= prices[right])
                left = right++;
            
            if( right == prices.size() ) break;

            while(right < prices.size()-1 && prices[right] < prices[right+1])
                right++;

            sum += prices[right] - prices[left];

            left = ++right;
        }

        return sum;
    }
};