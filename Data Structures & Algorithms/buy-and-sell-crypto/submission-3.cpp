class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // if d1 > d2, for d3~dn sell:
        // d1 buy always has less income than d2 buy
        // don't need to check d1Bd3S, d1Bd4S...
        // only need to check for d2Bd3S, d2Bd4S
        int l = 0, r = l + 1;
        int max = 0;
        while(r > l && r < prices.size())
        {
            cout << l << "/" << r << endl;
            int profit = prices[r] - prices[l];
            if(profit > max)
                max = profit;
            if(prices[l] > prices[r])
            {
                l++;
                r = l + 1;
            }
            else
            {
                r++;
            }
        }
        return max;
    }
};
