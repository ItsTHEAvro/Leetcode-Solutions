class Solution {
public:
    int possibleStringCount(string word) {
        int count = 1;

        for (int i = 0; i < word.length(); ) {
            char currentChar = word[i];
            int j = i;
            while (j < word.length() && word[j] == currentChar) {
                j++;
            }

            int blockLength = j - i;
            if (blockLength > 1) {
                count += (blockLength - 1);
            }
            i = j;
        }

        return count;
    }
};