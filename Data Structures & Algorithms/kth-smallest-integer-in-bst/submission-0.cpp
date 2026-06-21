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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        stack<TreeNode*> st;
        TreeNode* temp = root;

        while(temp){
            st.push(temp);
            temp = temp->left;
        }

        while(!st.empty()){
            if(k == 1){
                ans = (st.top())->val;
            }

            TreeNode* curr = st.top();
            st.pop();
            TreeNode* currRight = curr->right;
            
            while(currRight){
                st.push(currRight);
                currRight = currRight->left;
            }
            k--;
        }

        return ans;
    }
};
