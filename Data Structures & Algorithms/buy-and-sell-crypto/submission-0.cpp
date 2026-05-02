class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // first brute force, next consider which case doesn't need to be consiered
        // brute force
        int max = 0;
        for(int i = 0; i < prices.size() - 1; i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                if(profit > max)
                {
                    max = profit;
                }
            }
        }
        return max;
    }
};
