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
    int dfs(TreeNode* node, bool isLeft) {
        if (node == nullptr) return 0;
        
        if (!node->left && !node->right) {
            if(isLeft) return node->val;
            else return 0;
        }
        
        int ans = dfs(node->left, true);
        ans += dfs(node->right, false);
        
        return ans;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};