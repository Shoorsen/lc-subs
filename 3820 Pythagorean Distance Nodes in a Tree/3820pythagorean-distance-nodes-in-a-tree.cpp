class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0]; int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto bfs = [&](int node) -> std::vector<long long> {
            std::queue<int> queue;
            queue.push(node);
            std::vector<long long> dist(n, -1);
            dist[node] = 0;
            while (!queue.empty()) {
                long long u = queue.front();
                queue.pop();
                for (auto neighbor : adj[u]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[u] + 1;
                        queue.push(neighbor);
                    }
                }
            }
            return dist;
        };

        std::vector<std::vector<long long>> ds = {bfs(x), bfs(y), bfs(z)};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long dx = ds[0][i] * ds[0][i];
            long long dy = ds[1][i] * ds[1][i];
            long long dz = ds[2][i] * ds[2][i];
            if (dx + dy == dz) {
                ans++;
            }
            else if (dy + dz == dx) {
                ans++;
            }
            else if (dx + dz == dy) {
                ans++;
            }
        }
        return ans;


    }
};
