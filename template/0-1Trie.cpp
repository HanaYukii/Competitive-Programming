// 0-1 Trie (maximum XOR queries)
#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int MAXN = 2e5+5;
struct node
{
    int ch[2];
    int cnt;
    node() {
        memset(ch, 0, sizeof(ch));
        cnt = 0;
    }
}node[MAXN * 30];
int tot;
void ins(int x) {
    int cur = 0;
    for (int i = 29 ; i >= 0 ; i--) {
        int c = !!(x & (1<<i));
        if (!node[cur].ch[c]) {
            node[cur].ch[c] = ++tot;
            cur = tot;
        }
        else {
            cur = node[cur].ch[c];
        }
    }
    node[cur].cnt++;
}
int dfs(int x) {
    if (node[x].cnt) {
        return node[x].cnt;
    }
    if (!node[x].ch[0]) {
        return dfs(node[x].ch[1]);
    }
    else if (!node[x].ch[1]) {
        return dfs(node[x].ch[0]);
    }
    return max(dfs(node[x].ch[0]),dfs(node[x].ch[1])) + 1;
}
void go() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ins(x);
    }
    cout << n - dfs(0) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
