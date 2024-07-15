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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*>mp;
        map<int, vector<int>>childOf;
        int n = descriptions.size();
        for(int i = 0; i < n; i++){
            int parent = descriptions[i][0], child = descriptions[i][1];
            bool isLeft = descriptions[i][2] == 1;
            TreeNode* parentNode;
            TreeNode* childNode;
            if(mp.find(parent) == mp.end()){
                parentNode = new TreeNode(parent);
                mp[parent] = parentNode;
            } else {
                parentNode = mp[parent];
            }
            if(mp.find(child) == mp.end()){
                childNode = new TreeNode(child);
                mp[child] = childNode; 
            } else {
                childNode = mp[child];
            }
            
            if(isLeft){
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
            childOf[child].push_back(parent);
            childOf[parent];
        }
        
        for(auto [node, parents]: childOf){
            if(parents.empty()){
                return mp[node];
            }
        }
        return NULL;
    }
};