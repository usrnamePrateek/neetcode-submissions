/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);

        string res = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                res.push_back('#');
                res.push_back(',');
                continue;
            }

            res += to_string(node->val);
            res.push_back(',');

            q.push(node->left);
            q.push(node->right);
        }

        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }

        // cout << data << endl;
        queue<TreeNode*> q;
        int start = 0;
        pair<string, int> nodeData = getVal(data, start);
        TreeNode* root = new TreeNode(stoi(nodeData.first));

        q.push(root);
        while (nodeData.second < data.size()) {
            TreeNode* node = q.front();
            q.pop();

            nodeData = getVal(data, nodeData.second);
            // cout << nodeData.first << " " << nodeData.second << endl;

            if (nodeData.first == "#") {
                node->left = NULL;
            } else {
                TreeNode* left = new TreeNode(stoi(nodeData.first));
                node->left = left;
                q.push(left);
            }

            nodeData = getVal(data, nodeData.second);
            if (nodeData.first == "#") {
                node->right = NULL;
            } else {
                TreeNode* right = new TreeNode(stoi(nodeData.first));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }

    pair<string, int> getVal(string data, int start) {
        int len = 0;
        int init = start;

        while (start < data.size() && data[start] != ',') {
            start++;
            len++;
        }

        return {data.substr(init, len), start + 1};
    }
};
