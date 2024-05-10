class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n  = arr.size();
        
        priority_queue<vector<double>> pq;
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                double frac = (double)arr[i] / arr[j];
                pq.push({frac, (double)arr[i], (double)arr[j]});
                if(pq.size() > k) pq.pop();
            }
        }
        
        vector<double> tmp = pq.top();
        vector<int> res(2);
        
        res[0] = tmp[1];
        res[1] = tmp[2];
        
        return res; 
    }
};