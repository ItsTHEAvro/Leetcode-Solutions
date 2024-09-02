class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0l);
        
        k %= sum;
        
        for(int i=0; i<n; i++) {
            if ((k -= chalk[i]) < 0) return i;
        }

        return 0;
    }
};