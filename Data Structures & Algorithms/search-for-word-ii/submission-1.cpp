class PrefixTree {
   public:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* trie;

    PrefixTree() { trie = new TrieNode(); }

    void insert(string word) {
        TrieNode* temp = trie;
        for (char& c : word) {
            int idx = c - 'a';
            if (!temp->children[idx]) {
                temp->children[idx] = new TrieNode();
            }

            temp = temp->children[idx];
        }
        temp->isEnd = true;
    }
};

class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree* pt = new PrefixTree();

        for (string& word : words) {
            pt->insert(word);
        }

        vector<string> res;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string currWord = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                sol(board, i, j, pt->trie, visited, res, currWord);
            }
        }

        return res;
    }

    void sol(vector<vector<char>>& board, int i, int j, PrefixTree::TrieNode* trie,
             vector<vector<bool>>& visited, vector<string>& res, string& currWord) {
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || visited[i][j]) {
            return;
        }

        if (trie->children[board[i][j] - 'a']) {
            currWord.push_back(board[i][j]);
            if ((trie->children[board[i][j] - 'a'])->isEnd) {
                res.push_back(currWord);
                (trie->children[board[i][j] - 'a'])->isEnd = false;
            }

            visited[i][j] = true;
            sol(board, i + 1, j, trie->children[board[i][j] - 'a'], visited, res, currWord);
            sol(board, i - 1, j, trie->children[board[i][j] - 'a'], visited, res, currWord);
            sol(board, i, j + 1, trie->children[board[i][j] - 'a'], visited, res, currWord);
            sol(board, i, j - 1, trie->children[board[i][j] - 'a'], visited, res, currWord);

            currWord.pop_back();
            visited[i][j] = false;
        }
    }
};
