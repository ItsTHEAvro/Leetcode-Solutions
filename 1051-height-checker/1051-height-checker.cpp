class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        int cnt = 0;
        
        sort(sorted.begin(), sorted.end());
        
        for(int i=0; i<heights.size(); i++) {
                cnt+=(heights[i] != sorted[i]);
        }
        
        return cnt;
    }
};