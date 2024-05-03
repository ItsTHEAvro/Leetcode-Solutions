class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size(), i = 0, j = 0;
        
        while(i < n || j < m) {
            int tmp1 = 0, tmp2 = 0;
            
            while(i < n && version1[i] != '.') {
                tmp1 = tmp1 * 10 + (version1[i] - '0');
                i++;
            }
            
            i++;
            
            while(j < m && version2[j] != '.') {
                tmp2 = tmp2 * 10 + (version2[j] - '0');
                j++;
            }
            
            j++;
            
            if (tmp1 > tmp2) return 1;
            if (tmp1 < tmp2) return -1;
        }
        
        return 0;
    }
};
