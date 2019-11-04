#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int MAXN = 1e4 + 5;
set<pair<int, int> > ans;
// LatexBegin
struct Graph { int V, stamp;
  struct Node : vector<Node*> {
    int low, dfn; bool is_cut; Node *pa;
    Node() { low = dfn = -1;
      is_cut = false; pa = NULL;
    }
  }_memN[MAXN], *node[MAXN];
  Graph (int V) : V(V) { stamp = 0;
    for (int i = 0 ; i < V ; i++)
      node[i] = _memN + i;
  }
  void addEdge(int u, int v) {
    node[u]->push_back(node[v]);
    node[v]->push_back(node[u]);
  }
  void Tarjan(Node *u, Node *pa) {
    u->pa = pa; u->dfn = u->low = ++stamp;
    for (auto &v : *u) if (!~v->dfn)
      Tarjan(v, u), u->low = min(u->low, v->low);
    else if (pa != v)
      u->low = min(u->low, v->dfn);
  }
  void CutBridge() { int rt_son = 0;
    Tarjan(node[0], NULL);
    for (int i = 1 ; i < V ; i++) {
      Node *pa = node[i]->pa;
      if (pa == node[0]) rt_son++;
      else if (node[i]->low >= pa->dfn)
        pa->is_cut = true;
    }
    if (rt_son > 1) node[0]->is_cut = true;
    for (int i = 0 ; i < V ; i++)
      if (node[i]->is_cut)
        /* node[i] is a cut */;
    for (int i = 0 ; i < V ; i++) {
      Node *pa = node[i]->pa;
      if (pa && node[i]->low > pa->dfn)
        /* pa and node[i] is a bridge */;
    }
// LatexEnd
    for (int i = 0 ; i < V ; i++) {
      Node *pa = node[i]->pa;
      if (pa && node[i]->low > pa->dfn) {
        pair<int, int> e = {pa - _memN, node[i] - _memN};
        if (e.first > e.second)
          swap(e.first, e.second);
        ans.insert(e);
      }
    }
// LatexBegin
  }
};
int d[10005];
int fi(int x){
    return d[x] == x ? x : d[x] = fi(d[x]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; while (cin >> n >> m && n) {
    Graph *sol = new Graph(n); ans.clear();
    vector<pair<int,int> >vv;
    while (m--) {
      int u, v; cin >> u >> v;
      vv.pb({u,v});
      sol->addEdge(u, v);
    }
    sol->CutBridge();
    f(n){
        d[i] = i;
    }
    for(auto i:vv){
        if(ans.count(i))continue;
        swap(i.F,i.S);
        if(ans.count(i))continue;
        int x = fi(i.F);
        int y = fi(i.S);
        d[x] = y;
    }
    int tar = fi(0);
    int cnt = 0;
    f(n){
        if(fi(i)==tar){
            cnt++;
        }
    }
    cout << cnt << endl;
    delete sol;
  }
}
