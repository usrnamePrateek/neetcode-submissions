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

    bool search(string word) {
        TrieNode* temp = trie;
        for (char& c : word) {
            int idx = c - 'a';
            if (!temp->children[idx]) {
                return false;
            }

            temp = temp->children[idx];
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = trie;
        for (char& c : prefix) {
            int idx = c - 'a';
            if (!temp->children[idx]) {
                return false;
            }

            temp = temp->children[idx];
        }

        return true;
    }
};
