class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int lastMinIdx = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= lastMinIdx) {
               lastMinIdx = i;
            }
        }

        return lastMinIdx == 0;
    }
};
