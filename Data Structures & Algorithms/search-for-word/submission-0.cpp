class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (sol(board, i, j, 0, word, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool sol(vector<vector<char>>& board, int i, int j, int currIdx, string& word,
             vector<vector<bool>>& visited) {
        if (currIdx == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || visited[i][j] ||
            word[currIdx] != board[i][j]) {
            return false;
        }
        
        bool res = false;
        visited[i][j] = true;
        res = res || sol(board, i - 1, j, currIdx + 1, word, visited);
        res = res || sol(board, i + 1, j, currIdx + 1, word, visited);
        res = res || sol(board, i, j - 1, currIdx + 1, word, visited);
        res = res || sol(board, i, j + 1, currIdx + 1, word, visited);
        visited[i][j] = false;

        return res;
    }
};
