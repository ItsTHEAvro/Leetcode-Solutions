class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n  = arr.size();
        
        // min-heap {fraction, i, j}
        priority_queue<vector<double>, vector<vector<double>>, greater<vector<double>>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push({(double)arr[i]/arr[n-1], (double)i, (double)(n-1)});
        }
        
        int cnt = 1;
        while(cnt < k) {
            vector<double> vec = pq.top();
            pq.pop();
            int i = vec[1];
            int j = vec[2] - 1;
            pq.push({(double)arr[i]/arr[j], (double)i, (double)j});
            cnt++;
        }
        
        vector<double> res = pq.top();
        int i = res[1];
        int j = res[2];
        
        return {arr[i], arr[j]};
    }
};