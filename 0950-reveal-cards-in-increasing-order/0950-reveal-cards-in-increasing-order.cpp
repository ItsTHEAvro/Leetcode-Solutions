class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> res(n);
        queue<int> arr;
        
        sort(deck.begin(), deck.end());
        
        for(int i=0; i<n; i++) arr.push(i);
        
        for(int card:deck) {
            int next = arr.front();
            arr.pop();
            res[next] = card;
            if(!arr.empty()) {
                arr.push(arr.front());
                arr.pop();
            }
        }
        
        return res;
        
    }
};