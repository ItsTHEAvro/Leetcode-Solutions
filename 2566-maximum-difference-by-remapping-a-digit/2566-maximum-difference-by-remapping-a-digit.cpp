class Solution {
public:
    int minMaxDifference(int num) {
        string numStr = to_string(num);

        // find the maximum possible number
        string maxNumStr = numStr;
        char digitForMax = maxNumStr[0];

        // find the digit to change to nine
        for(char c:maxNumStr){
            if(c != '9'){
                digitForMax = c;
                break;
            }
        }
        // change all occurrences of that digit to nine
        for(char &c : maxNumStr){
            if(c == digitForMax){
                c = '9';
            }
        }
        int maxValue = stoi(maxNumStr);

        // find the minimum possible number
        string minNumStr = numStr;
        char digitForMin = minNumStr[0];

        // change all occurrences of the first digit to zero
        for(char &c : minNumStr){
            if(c == digitForMin){
                c = '0';
            }
        }
        int minValue = stoi(minNumStr);

        // calculate and return the difference
        return maxValue - minValue;
    }
};
