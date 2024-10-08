class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        unsigned mask = ~0;
        while(mask & n) mask <<= 1;
        return (~mask ^ n);
    }
};