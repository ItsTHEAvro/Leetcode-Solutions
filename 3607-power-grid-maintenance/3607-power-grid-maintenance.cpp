class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        struct DSU {
            vector<int> parent, size;
            DSU(int n) {
                parent.resize(n+1);
                size.assign(n+1, 1);
                iota(parent.begin(), parent.end(), 0);
            }
            
            int find(int x) {
                return parent[x] == x ? x : parent[x] = find(parent[x]);
            }

            void unite(int a, int b) {
                a = find(a), b = find(b);
                if (a == b) return;
                if (size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        };
        
        DSU dsu(c);
        for (auto &e : connections) dsu.unite(e[0], e[1]);

        unordered_map<int, set<int>> online;
        for (int i = 1; i <= c; i++)
            online[dsu.find(i)].insert(i);

        vector<int> res;
        vector<bool> isOnline(c+1, true);

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);
            if (type == 1) { // maintenance
                if (isOnline[x]) res.push_back(x);
                else if (!online[root].empty()) res.push_back(*online[root].begin());
                else res.push_back(-1);
            } else {  // offline
                if (isOnline[x]) {
                    isOnline[x] = false;
                    online[root].erase(x);
                }
            }
        }
        return res;
    }
};
