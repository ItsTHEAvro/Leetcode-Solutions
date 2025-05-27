class Solution {
public:
    int differenceOfSums(int n, int m) {
        int div = 0, nonDiv = 0;
        for(int i=1; i<=n; i++) {
            (i%m == 0)?div += i:nonDiv += i;
        }

        return (nonDiv - div);
    }
};