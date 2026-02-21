// Dijkstra's shortest path (priority queue)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector<pair<int,int>> g[MAXN];
int dis[MAXN];
int n;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dij(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (dis[now.second] != now.first) continue;
        for (auto &e : g[now.second]) {
            if (now.first + e.second < dis[e.first]) {
                dis[e.first] = now.first + e.second;
                pq.push({dis[e.first], e.first});
            }
        }
    }
}

int main() {

}
