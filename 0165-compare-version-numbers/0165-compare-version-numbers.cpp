class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        
        int n = version1.size(), m = version2.size(), i = 0, j = 0;
        
        while(i < n || j < m) {
            int tmp = 0;
            
            while(i < n && version1[i] != '.') {
                tmp = tmp * 10 + (version1[i] - '0');
                i++;
            }
            
            v1.push_back(tmp);
            i++;
            
            tmp = 0;
            
            while(j < m && version2[j] != '.') {
                tmp = tmp * 10 + (version2[j] - '0');
                j++;
            }
            
            v2.push_back(tmp);
            j++;
        }
        
        for(i = 0; i < min(v1.size(), v2.size()); i++) {
            if(v1[i] > v2[i]) return 1;
            if(v1[i] < v2[i]) return -1;
        }
        
        return 0;
    }
};