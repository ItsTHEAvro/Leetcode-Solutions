class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);

        for (int num : nums) freq[min(n, num)]++;

        int x = 0;

        for (int i = n; i > 0; i--) {
            x += freq[i];
            if (i == x) return i;
        }

        return -1;
    }
};