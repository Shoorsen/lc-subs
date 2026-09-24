class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int l = 0;
        int cur_profit = 0;
        for (int r = 0; r < prices.size(); r++) {
            cur_profit = prices[r] - prices[l];
            if (prices[r] < prices[l]) {
                l = r;
                continue;
            }

            if (cur_profit > profit) {
                profit = cur_profit;
            }
        }
        return profit;
    }
};

