class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int maxSize = 0;

        for (int& num : nums) {
            numSet.insert(num);
        }

        for (int& num : nums) {
            int temp = num;

            while (numSet.count(temp - 1) != 0) {
                temp--;
            }

            int size = 1;
            while (numSet.count(temp + 1) != 0) {
                numSet.erase(temp);
                temp++;
                size++;
            }

            maxSize = max(maxSize, size);
        }

        return maxSize;
    }
};
