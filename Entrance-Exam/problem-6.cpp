#include <bits/stdc++.h>
using namespace std;

struct Node {
    int vertex, weight;
    Node(int v, int w) : vertex(v), weight(w) {}
};

vector<vector<Node>> adj; 

vector<int> dijkstra(int src, int n) {
    vector<int> dist(n, INT_MAX); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (const Node& neighbor : adj[u]) {
            int v = neighbor.vertex, w = neighbor.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n);
    
    int p;
    cin >> p;
    vector<int> venues(p);
    for (int &v : venues) cin >> v;
    
    int t;
    cin >> t;
    
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        adj[u].emplace_back(v, l);
        adj[v].emplace_back(u, l);
    }
    
    int maxDist = 0;

    for (int venue : venues) {
        vector<int> dist = dijkstra(venue, n);
        for (int other : venues) {
            maxDist = max(maxDist, dist[other]);
        }
    }
    
    double minSpeed = (double) maxDist / (t * 60);
    cout << fixed << setprecision(3) << minSpeed << endl;

    return 0;
}
