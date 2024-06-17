class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = (long) sqrt(c), sum;
        
        while(l <= r){
            sum = (l*l) + (r*r);
            if(sum < c) l++;
            else if(sum > c) r--;
            else return true;
        }
        
        return c == 1;
    }
};