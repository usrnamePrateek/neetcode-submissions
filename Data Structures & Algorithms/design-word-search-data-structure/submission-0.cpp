class WordDictionary {
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
    WordDictionary() { trie = new TrieNode(); }

    void addWord(string word) {
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

    bool search(string word) { return sol(word, trie, 0); }

    bool sol(string& word, TrieNode* trie, int idx) {
        if (idx == word.size()) {
            return trie->isEnd;
        }

        if (word[idx] == '.') {
            bool res = false;
            for (int i = 0; i < 26; i++) {
                if (trie->children[i])
                    res = res || sol(word, trie->children[i], idx + 1);
            }

            return res;
        }

        else if (!trie->children[word[idx] - 'a']) {
            return false;
        } else {
            return sol(word, trie->children[word[idx] - 'a'], idx + 1);
        }
    }
};
