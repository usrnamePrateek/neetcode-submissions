class Solution {
   public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        return max(sol(nums, 0, nums.size() - 1), sol(nums, 1, nums.size()));
    }

    int sol(vector<int> nums, int start, int end) {
        if (start >= end) {
            return 0;
        }

        int prev2 = 0;
        int prev1 = nums[start];
        int curr = nums[start];

        for (int i = start + 1; i < end; i++) {
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};
