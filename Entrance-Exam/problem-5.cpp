#include <bits/stdc++.h>
using namespace std;

int findLargestConnectedTree(vector<vector<int>> &tree, unordered_set<int> &traitorNodes, vector<bool> &visited, int root) {
    if (traitorNodes.count(root) || visited[root]) return 0;

    queue<int> q;
    q.push(root);
    visited[root] = true;
    int size = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        size++;

        for (int child : tree[node]) {
            if (!traitorNodes.count(child) && !visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> tree(n);
    unordered_set<int> traitorNodes;
    vector<bool> visited(n, false);
    vector<int> parents(n, -1);  

    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
        parents[i] = parent;  
    }

    for (int i = 0; i < m; i++) {
        int traitor;
        cin >> traitor;
        traitorNodes.insert(traitor);
    }

    int maxConnectedSize = 0;

    for (int i = 0; i < n; i++) {
        if (!traitorNodes.count(i) && (parents[i] == -1 || traitorNodes.count(parents[i]))) {
            maxConnectedSize = max(maxConnectedSize, findLargestConnectedTree(tree, traitorNodes, visited, i));
        }
    }

    cout << maxConnectedSize << "\n";
    return 0;
}
