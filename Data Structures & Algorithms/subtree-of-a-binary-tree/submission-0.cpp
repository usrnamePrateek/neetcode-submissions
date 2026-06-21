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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (isSubtreeHelper(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSubtreeHelper(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        }

        if (!root && subRoot || root && !subRoot) {
            return false;
        }

        return root->val == subRoot->val && isSubtreeHelper(root->left, subRoot->left) &&
               isSubtreeHelper(root->right, subRoot->right);
    }
};
