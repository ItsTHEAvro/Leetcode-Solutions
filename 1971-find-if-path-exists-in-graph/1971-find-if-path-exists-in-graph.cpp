class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> graph;
    
    void dfs(int node) {
        if(vis[node]) return;
        vis[node] = true;
        
        for(int child:graph[node]) {
            dfs(child);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vis = vector<bool>(n, false);
        graph = vector<vector<int>>(n);
        
        for(auto edge:edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(source);
        
        return vis[destination];
    }
};