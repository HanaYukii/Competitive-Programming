#include<bits/stdc++.h>
using namespace std;

#define MAXN 5011

int N, M, K, id[MAXN];
int cnt, num[MAXN], low[MAXN];

stack<int> cur;
vector<int> adj[MAXN], rev[MAXN];
vector<vector<int> > scc;

void tarjan(int x) {
    cur.push(x);
    num[x] = low[x] = (++cnt);
    
    for (int nxt : adj[x]) {
        if (!num[nxt]){
            tarjan(nxt);
            low[x] = min(low[x], low[nxt]);
        } else if (!id[nxt]) {
            low[x] = min(low[x], num[nxt]);
        }
    }
    
    if (num[x] == low[x]) {
        scc.push_back(vector<int>());
        while (cur.size() && num[cur.top()] >= num[x]) {
            scc.back().push_back(cur.top());
            id[cur.top()] = (int)scc.size();
            cur.pop();
        }
    }
}



int main()
{
    if (fopen("data.in", "r"))
        freopen("data.in", "r", stdin);
    
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++)
        if (!num[i]) tarjan(i);
    
    int ans = 0;
    for (int i = 0; i < scc.size(); i++) {
        bool flag = true;
        for (int j : scc[i])
            for (int k : rev[j])
                flag &= (id[k]==id[j]);
        
        ans += flag*(id[K] != i+1);
    }
    
    printf("%d\n", ans);
}