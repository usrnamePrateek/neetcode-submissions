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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        sol(root, maxSum);
        return maxSum;
    }

    int sol(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = sol(root->left, maxSum);
        int rightSum = sol(root->right, maxSum);

        maxSum = max(root->val + max(leftSum, 0) + max(rightSum, 0), maxSum);
        return root->val + max({leftSum, rightSum, 0});
    }
};
