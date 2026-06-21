class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int max_ = 0;
        int currPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < currPrice) {
                currPrice = prices[i];
                continue;
            }

            max_ = max(max_, prices[i] - currPrice);
        }

        return max_;
    }
};
