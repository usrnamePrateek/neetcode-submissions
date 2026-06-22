class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        // vector<pair<int, int>> dp(nums.size());
        int first = nums[0];
        int second = nums[0];
        int maxP = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int one = nums[i] * first;
            int two = nums[i] * second;

            first = max(nums[i], max(one, two));
            second = min(nums[i], min(one, two));

            maxP = max(first, maxP);
        }

        return maxP;
    }
};
