class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i : leaves) {
                int j = *(adj[i].begin());
                adj[j].erase(i);
                if (adj[j].size() == 1) newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
