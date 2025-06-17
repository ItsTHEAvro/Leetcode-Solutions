class Solution {
public:
    long long MOD = 1e9 + 7;
    long long fact[100001]; 

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while(exp > 0) {
            if(exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInv(long long n) { 
        return power(n, MOD - 2);
    }

    void precompFact(int n_max) { 
        fact[0] = 1;
        for(int i = 1; i <= n_max; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
    }

    long long nCr_mod_p(int n, int r) {
        if(r < 0 || r > n) return 0;
        long long num = fact[n];
        long long den = (fact[r] * fact[n - r]) % MOD;
        return (num * modInv(den)) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precompFact(n - 1);

        long long C = nCr_mod_p(n - 1, k); 
        long long M_choices = m; 
        
        long long nm_term = 0; 
        if((n - 1 - k) == 0) nm_term = 1;
        else if(m - 1 == 0) nm_term = 0;
        else nm_term = power(m - 1, (n - 1 - k));
        
        long long ans = (C * M_choices) % MOD;
        ans = (ans * nm_term) % MOD;

        return ans;
    }
};