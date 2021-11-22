// Question link : https://leetcode.com/problems/bus-routes/

class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, set<int>> graph;
        for (int r = 0; r < routes.size(); r++) {
            for (int stop : routes[r]) {
                graph[stop].insert(r);
            }
        }
        unordered_set<int> visited;
        queue<int> q;
        for (int route : graph[source]) {
            q.push(route);
            visited.insert(route);
        }
        int size, ans = 0;
        while (!q.empty()) {
            ++ans;
            size = q.size();
            for (int i = 0; i < size; i++) {
                int route = q.front();
                q.pop();
                for (int stop : routes[route]) {
                    if (stop == target) {
                        return ans;
                    }
                    for (int nextRoute : graph[stop]) {
                        if (!visited.count(nextRoute)) {
                            visited.insert(nextRoute);
                            q.push(nextRoute);
                        }
                    }
                }
            }
        }
        return -1;
    }
};