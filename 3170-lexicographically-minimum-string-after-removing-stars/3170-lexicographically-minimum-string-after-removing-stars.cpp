class Solution {
public:
    string clearStars(string s) {
        map<char, vector<int>> charIndices;
        
        // a list to mark which letters to scrap
        vector<bool> removed(s.length(), false);

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                removed[i] = true; // mark the star for removal

                // make sure there's something to remove
                if(!charIndices.empty()){
                    // grab the smallest character we've seen
                    auto it = charIndices.begin();
                    
                    // rightmost spot
                    int idxToRemove = it->second.back();
                    
                    removed[idxToRemove] = true; // mark that character for removal too

                    it->second.pop_back(); // take that spot off the list

                    // if that was the last one, forget this char
                    if(it->second.empty()) charIndices.erase(it);
                }
            } else{
                // not a star, so just remember where this letter is
                charIndices[s[i]].push_back(i);
            }
        }
        string res = "";
        for(int i = 0; i < s.length(); i++){
            // add the character if we didn't mark it for removal
            if(!removed[i]) res += s[i];
        }
        return res;
    }
};