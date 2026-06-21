class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int prev2 = 0;
        int prev1 = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};
