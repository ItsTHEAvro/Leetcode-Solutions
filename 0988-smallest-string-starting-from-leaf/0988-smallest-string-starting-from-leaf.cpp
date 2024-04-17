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
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        dfs(root, "", ans);
        return ans;
    }
    
    void dfs(TreeNode* root, string path, string& curr) {
        if(root == nullptr) return;
        
        path += char('a' + root->val);
        
        if(root->left == nullptr && root->right == nullptr) {
            reverse(path.begin(), path.end());
            if(curr.empty() || curr > path) curr = path;
            reverse(path.begin(), path.end());
        }
        
        dfs(root->left, path, curr);
        dfs(root->right, path, curr);
    }
};