class Solution {
public:
    long long ways_to_distribute(int n) {
        if(n < 0) return 0;
        return (n + 2LL) * (n + 1LL) / 2LL;
    }

    long long distributeCandies(int n, int limit) {
        long long res = 0;
        res = ways_to_distribute(n);
        res -= 3 * ways_to_distribute(n - (limit + 1));
        res += 3 * ways_to_distribute(n - 2 * (limit + 1));
        res -= 1 * ways_to_distribute(n - 3 * (limit + 1));

        return res;
    }
};