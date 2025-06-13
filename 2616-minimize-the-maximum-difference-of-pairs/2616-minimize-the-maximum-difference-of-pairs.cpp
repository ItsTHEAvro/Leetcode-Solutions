class Solution {
public:
    bool check(const vector<int>& a, int p, int t) {
        int cnt = 0;
        for (int i = 0; i < a.size() - 1;) {
            if (t >= (a[i + 1] - a[i])) {
                cnt++;
                i += 2;
            } else i++;
            if (cnt >= p) return true;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, h = nums[n - 1] - nums[0];
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(nums, p, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};