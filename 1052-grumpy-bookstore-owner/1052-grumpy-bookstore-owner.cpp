class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, mx = 0;

        for(int i = 0, extra = 0; i < grumpy.size(); i++){
            if(grumpy[i] == 0) {
                res += customers[i];
            }
            
            if(grumpy[i] == 1) {
                extra += customers[i];
            }
            
            if(i >= minutes && grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }
            
            mx = max(mx, extra);
        }
        
        return res + mx;
    }
};