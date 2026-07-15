class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subRes;
        sol(nums, 0, subRes);
        return res;
    }

    void sol(vector<int>&nums, int idx, vector<int> &subRes){
        if(idx == nums.size()){
            res.push_back(subRes);
            return;
        }

        sol(nums, idx + 1, subRes);

        subRes.push_back(nums[idx]);
        sol(nums, idx + 1, subRes);
        subRes.pop_back();
    }
};
