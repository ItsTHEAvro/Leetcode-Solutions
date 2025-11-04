class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;

        for(int i=0; i<k; i++) freq[nums[i]]++;
        
        ans.push_back(xSum(freq, x));
        for (int i = 1; i <= n - k; i++) {

            // delete left
            freq[nums[i - 1]]--;
            if (freq[nums[i - 1]] == 0) {
                freq.erase(nums[i - 1]);
            }

            // add right
            freq[nums[i + k - 1]]++;

            // x-sum for the current window
            ans.push_back(xSum(freq, x));
        }

        return ans;

    }

private:
    int xSum(unordered_map<int, int>& freq, int x) {
        priority_queue<pair<int, int>> pq;

        for(auto& p:freq) pq.push({p.second, p.first});

        int sum = 0;

        for(int i=0; i < x && !pq.empty(); i++) {
            pair<int, int> top = pq.top();
            sum += top.second * top.first;
            pq.pop();
        }

        return sum;
    }

};
