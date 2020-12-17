#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>>g[maxn];
int dis[maxn];
int n;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void dij(int x) {
    pq.push({0,1});
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (dis[now.S] != now.F)continue;
        for (auto &i : g[now.S]) {
            if (now.F + i.S < dis[i.F]) {
                dis[i.F] = now.F + i.S;
                pq.push({dis[i.F], i.F});
            }
        }
    }
} 
int main() {

}