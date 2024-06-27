class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int arr[100010] = {0};
        
        for(vector<int> edge:edges) {
            for(int node:edge) {
                arr[node]++;
            }
        }
        
        int node = 0;
        
        for(; node < 100010; node++) {
            if(arr[node] == edges.size()) {
                return node;
            }
        }
        
        return node;
    }
};