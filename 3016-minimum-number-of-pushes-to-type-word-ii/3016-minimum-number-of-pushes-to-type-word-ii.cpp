class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto &e: word) mp[e]++;

        int ans = 0;
        priority_queue<pair<int,int>>pq;

        for(auto &[f,s]:mp) pq.push({s,f});

        int click = 1, button= 0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            ans += p.first * click;
            button++;
            
            if(button == 8){
                click++;
                button = 0;
            }
        }
        return ans;
    }
};