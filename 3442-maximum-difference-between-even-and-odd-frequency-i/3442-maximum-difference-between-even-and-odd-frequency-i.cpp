class Solution {
public:
    int maxDifference(string s) {
        map<char, int> charFreqs;
        for(char chr:s) charFreqs[chr]++;

        int maxOddFreq = -1;
        int minEvenFreq = 1e9 + 7; 

        for(auto const& [key, val]:charFreqs) {
            if(val&1) maxOddFreq = max(maxOddFreq, val);
            else minEvenFreq = min(minEvenFreq, val);
        }
        
        if(maxOddFreq == -1 || minEvenFreq == 1e9 + 7) return -1;

        return maxOddFreq - minEvenFreq;
    }
};