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

class Solution {
   public:
    bool isValidBST(TreeNode* root) { return sol(INT_MIN, root, INT_MAX); }

    bool sol(int min_, TreeNode* root, int max_) {
        if (!root) {
            return true;
        }

        if (root->val <= min_ || root->val >= max_) {
            return false;
        }

        return sol(min_, root->left, root->val) && sol(root->val, root->right, max_);
    }
};
