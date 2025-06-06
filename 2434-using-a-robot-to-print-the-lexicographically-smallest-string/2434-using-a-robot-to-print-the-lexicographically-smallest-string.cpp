class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        string t = "";
        vector<int> cnt(26, 0);

        // get frequency and find initial smallest char
        for(char c : s) cnt[c - 'a']++;
        int min_ch = 0;
        while(min_ch < 26 && cnt[min_ch] == 0) min_ch++;

        for(char c : s) {
            t.push_back(c);
            cnt[c - 'a']--;

            // if the smallest char is no longer in s find the new one
            while(min_ch < 26 && cnt[min_ch] == 0) min_ch++;

            // pop from t if its char is <= the smallest available in s
            while(!t.empty() && (min_ch == 26 || t.back() - 'a' <= min_ch)) {
                ans.push_back(t.back());
                t.pop_back();
            }
        }

        return ans;
    }
};