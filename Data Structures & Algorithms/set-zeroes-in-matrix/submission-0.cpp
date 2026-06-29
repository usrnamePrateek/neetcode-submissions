class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> cols(matrix[0].size());
        vector<int> rows(matrix.size());

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if(!matrix[i][j]){
                    cols[j] = 1;
                    rows[i] = 1;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if(cols[j] || rows[i]){
                   matrix[i][j] = 0;
                }
            }
        }
    }
};
