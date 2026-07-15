class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNum = -1;
        int m = matrix[0].size();
        int n = matrix.size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid][m - 1] == target) {
                return true;
            }

            if (matrix[mid][m - 1] > target) {
                rowNum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(rowNum == -1){
            return false;
        }

        low = 0, high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[rowNum][mid] == target) {
                return true;
            }

            if (matrix[rowNum][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
