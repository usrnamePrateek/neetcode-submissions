class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i <= nums.size(); i++) {
            if (i < nums.size()) res ^= nums[i];
            res ^= i;
        }

        return res;
    }
};
