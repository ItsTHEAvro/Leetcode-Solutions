class Solution {
public:
    int findLHS(vector<int>& n) {
        unordered_map<int, int> mp;
        int res = 0;

        for(int num : n) {
            mp[num]++;
            if(mp.count(num - 1)) {
                res = max(res, mp[num] + mp[num - 1]);
            }
            if(mp.count(num + 1)) {
                res = max(res, mp[num] + mp[num + 1]);
            }
        }
        return res;
    }
};