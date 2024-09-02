class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        
        for(const auto& i : chalk) sum += i;
        
        k %= sum;
        
        for(int i=0; i<n; i++) {
            if ((k -= chalk[i]) < 0) return i;
        }

        return 0;
    }
};