class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), res = 0;
        
        for(int i=0; i<n; i++) {
            int tmp = arr[i];
            
            for(int j=i+1; j<n; j++) {
                tmp ^= arr[j];
                
                if(tmp == 0) {
                    res += (j - i);
                }
            }
        }
        
        return res;
    }
};