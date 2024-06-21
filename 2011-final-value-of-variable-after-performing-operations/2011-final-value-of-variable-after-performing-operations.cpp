class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        
        for(string operation : operations) {
            if(operation[0] == '+' || operation[2] == '+') x++;
            else x--;
        }
        
        return x;
    }
};