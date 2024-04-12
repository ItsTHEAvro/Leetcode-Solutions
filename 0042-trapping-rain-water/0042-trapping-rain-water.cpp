class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> lmax;
        lmax.push_back(height[0]);
        for(int i=1; i<n; i++) {
            lmax.push_back(max(lmax[i-1],height[i]));
        }
        
        vector<int> rmax(n);
        rmax[n-1] = height[n-1];
        for (int i=n-2; i>=0; i--) {
            rmax[i] = max(rmax[i+1],height[i]);
        }
        
        vector<int> minmax;
        for(int i=0; i<n; i++) {
            minmax.push_back(min(lmax[i],rmax[i]));
        }
        
        int cnt=0;
        for(int i=0; i<n; i++) {
            cnt += (minmax[i]-height[i]);
        }
        
        return cnt;   
    }
};