class Solution {
public:
    int passThePillow(int n, int time) {
        int chunks = time / (n - 1);
        return (chunks&1) ? (n - time % (n - 1)) : (time % (n - 1) + 1) ;
    }
};
