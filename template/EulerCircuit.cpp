// Euler Circuit on undirected multigraph (Hierholzer's algorithm)
// - Finds an Euler circuit if one exists (all vertices have even degree)
// - Each edge gets a direction: edir[id] = which endpoint we started from
// - O(V + E)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

vector<pair<int,int>> g[MAXN]; // g[u] = {(v, edge_id), ...}
bool used[MAXN];               // used[edge_id]
int edir[MAXN];                // edir[edge_id]: 0 = from eu, 1 = from ev
int eu[MAXN], ev[MAXN];        // eu[id], ev[id] = endpoints of edge

void dfs(int u) {
  while (!g[u].empty()) {
    auto [v, id] = g[u].back();
    g[u].pop_back();
    if (used[id]) continue;
    used[id] = true;
    edir[id] = (u == eu[id] ? 0 : 1);
    dfs(v);
  }
}

// Returns true if Euler circuit exists and fills edir[].
// Call with vertices 1..n, edges 0..m-1.
bool euler_circuit(int n, int m) {
  for (int v = 1; v <= n; v++)
    if (g[v].size() % 2 != 0) return false;

  for (int i = 0; i < m; i++) used[i] = false;

  for (int v = 1; v <= n; v++)
    if (!g[v].empty()) dfs(v);

  return true;
}

// Usage:
// 1. Clear g[1..n]
// 2. For each edge i: set eu[i], ev[i], then
//      g[eu[i]].push_back({ev[i], i});
//      g[ev[i]].push_back({eu[i], i});
// 3. Call euler_circuit(n, m)
// 4. edir[i] == 0 means edge directed eu[i] -> ev[i]
//    edir[i] == 1 means edge directed ev[i] -> eu[i]
//
// Note: recursive dfs may stack overflow for large n.
//       Use iterative version below if needed.

// --- Iterative version (stack-safe) ---
// void dfs_iter(int s) {
//   stack<int> stk;
//   stk.push(s);
//   while (!stk.empty()) {
//     int u = stk.top();
//     if (g[u].empty()) { stk.pop(); continue; }
//     auto [v, id] = g[u].back();
//     g[u].pop_back();
//     if (used[id]) continue;
//     used[id] = true;
//     edir[id] = (u == eu[id] ? 0 : 1);
//     stk.push(v);
//   }
// }
