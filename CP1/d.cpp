#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n;
set< pair<int,int> > S;
// #location = S.size()

int par[MAXN], sz[MAXN];

int find(int x)
{
    if (par[x]==x)return x;
    return par[x] = find(par[x]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    S.erase({sz[u],u});
    S.erase({sz[v],v});
    par[v]=u;
    sz[u] += sz[v];
    S.insert( {sz[u],u} );
}

bool check()
{
    int l = S.begin()->first;
    int r = S.rbegin()->first;
    return l==r;
}

int main()
{
    vector< pair<int,int> > v; // ai, i

    scanf("%d", &n);
    for (int i=1, ai; i<=n; i++)
    {
        scanf("%d", &ai);
        v.push_back({ai,i});
    }
    sort(v.begin(),v.end());

    for (int i=1; i<=n; i++)
    {
        par[i] = -1;
        sz[i] = 0;
    }

    int loc=0;
    int ans = v.back().first+1;

    for (auto &p:v)
    {
        int x = p.second;
        par[x] = x, sz[x] = 1;
        S.insert({1,x});
        if (x>1 && par[x-1]!=-1) merge(x-1,x);
        if (x<n && par[x+1]!=-1) merge(x,x+1);
        if ( check() && S.size()>loc )
        {
            ans = p.first+1;
            loc = S.size();
        }
    }
    cout << ans << '\n';
}
