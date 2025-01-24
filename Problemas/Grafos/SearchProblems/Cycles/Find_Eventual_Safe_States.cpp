//https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    unordered_map<int, bool> safe;
    bool dfs(int i, vector<vector<int>>& graph){
        if (safe.find(i) != safe.end()) return safe[i];
        safe[i] = false;
        for (int nei : graph[i]) {
            if (!dfs(nei, graph)) return false;
        }
        safe[i] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        for (int i = 0; i < n; i++) 
            if (dfs(i, graph)) res.push_back(i);

        return res;
    }
};
