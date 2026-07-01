class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<int>>> checkList(3, vector<vector<int>>(3, vector<int>(9, 0)));
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    if (rows[i][board[i][j] - '1'] || cols[j][board[i][j] - '1'] ||
                        checkList[i / 3][j / 3][board[i][j] - '1']) {
                        return false;
                    }

                    rows[i][board[i][j] - '1'] = 1;
                    cols[j][board[i][j] - '1'] = 1;
                    checkList[i / 3][j / 3][board[i][j] - '1'] = 1;
                }
            }
        }

        return true;
    }
};
