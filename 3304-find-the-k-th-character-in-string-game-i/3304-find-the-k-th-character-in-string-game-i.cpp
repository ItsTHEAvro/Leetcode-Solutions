class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";

        while(word.length() < k) {
            string str = "";
            for(char c : word) {
                if(c == 'z') {
                    str += 'a';
                } else {
                    str += (char)(c + 1);
                }
            }
            word += str;
        }

        return word[k - 1];
    }
};