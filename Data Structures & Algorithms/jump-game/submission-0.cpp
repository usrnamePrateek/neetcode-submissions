class Solution {
   public:
    bool canJump(vector<int>& nums) {
        vector<int> poss(nums.size(), false);
        poss[nums.size() - 1] = true;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= nums.size() - 1) {
                poss[i] = true;
                continue;
            }

            int start = i + 1;
            while (start <= i + nums[i] && !poss[start]) {
                start++;
            }

            if (start <= i + nums[i]) {
                poss[i] = true;
            }
        }

        return poss[0];
    }
};
