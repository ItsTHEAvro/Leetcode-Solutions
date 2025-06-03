class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,  vector<int>& initialBoxes) {
        int n = status.size();
        int totalCandies = 0;
        
        queue<int> q; // boxes to open next
        
        vector<bool> haveBox(n, false);   
        vector<bool> haveKey(n, false);
        vector<bool> visited(n, false);

        // process initial set of boxes
        for (int box : initialBoxes) {
            haveBox[box] = true;
            if (status[box]) { // already open?
                if (!visited[box]) { // and not yet processed?
                    q.push(box); // add to queue
                    visited[box] = true; // mark as handled
                }
            }
        }

        // open boxes from the queue
        while (!q.empty()) {
            int currBox = q.front(); // get next box
            q.pop();
            
            totalCandies += candies[currBox]; // collect candies of the current box

            // check for keys in the current box
            for (int key : keys[currBox]) {
                haveKey[key] = true; // got new key
                
                // can this key open a box we have but haven't visited?
                if (haveBox[key] && !visited[key]) {
                    q.push(key); // yes, push it to the queue
                    visited[key] = true;
                }
            }

            // Check for boxes inside the current box
            for (int newBox : containedBoxes[currBox]) {
                haveBox[newBox] = true; 
                
                // is the new box open, or do we have a key and have we not visited it yet?
                if (!visited[newBox] && (status[newBox] == 1 || haveKey[newBox])) {
                    q.push(newBox);
                    visited[newBox] = true;
                }
            }
        }
        
        return totalCandies;
    }
};