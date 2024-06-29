class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int child, int curr, vector<vector<int>> &ans){
        vis[curr]=true;
        
        for(const auto &node:graph[curr]){
            if(!vis[node]){
                ans[node].push_back(child);
                dfs(graph,vis,child,node,ans);
            }
            
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), graph(n);
        
        for(auto &v:edges){
            graph[v[0]].push_back(v[1]);
        }
        
        for(int i=0; i<n; i++){
            vector<bool> vis(n);
            dfs(graph, vis, i, i, ans);
        }
        
        return ans;
    }
};