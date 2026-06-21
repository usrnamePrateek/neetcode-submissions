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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return sol(preorder, inorder, preIdx, 0, preorder.size() - 1);
    }

    TreeNode* sol(vector<int>& preorder, vector<int>& inorder, int& preIdx, int start, int end) {
        if(start > end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int mid = find(inorder.begin(), inorder.end(), preorder[preIdx]) - inorder.begin();

        preIdx++;
        root->left = sol(preorder, inorder, preIdx, start, mid - 1);
        root->right = sol(preorder, inorder, preIdx, mid + 1, end);

        return root;
    }
};
