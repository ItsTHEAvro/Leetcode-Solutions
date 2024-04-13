class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int row=matrix.size();
        int column=matrix[0].size();
        
        vector<int> heights(column+1, 0);
        
        int res=0;
        for (auto& row : matrix) {
            for (int i=0; i<column; i++) {
                if(row[i]=='1') heights[i]++;
                else heights[i]=0;
            }

            stack<int> st;
            
            for (int i=0; i<heights.size(); i++) {
                while (!st.empty() && heights[st.top()] > heights[i]) {
                    int currentHeight = heights[st.top()];
                    st.pop();
                    int currentWidth;
                    if(st.empty()) currentWidth=i; 
                    else currentWidth=i-st.top()-1;
                    res = max(res, currentHeight * currentWidth);
                }
                st.push(i);
            }
        }

        return res;
    }
};