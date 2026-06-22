class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());
        dp[0].first = nums[0];
        dp[0].second = nums[0];

        int maxP = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int one = nums[i] * dp[i - 1].first;
            int second = nums[i] * dp[i - 1].second;

            dp[i].first = max(nums[i], max(one, second));
            dp[i].second = min(nums[i], min(one, second));

            // cout << dp[i].first << " " << dp[i].second << endl;
            maxP = max(dp[i].first, maxP);
        }

        return maxP;
    }
};
