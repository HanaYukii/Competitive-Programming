//cses 2102
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 100005;
const int mod = 1e9 + 7;
int ans[maxn];
struct AC
{
    struct state
    {
        int nxt[26];
        int fail;
        vector<int>cnt;
    }node[500005];
    int sz;
    void init() {
        for (int i = 0 ; i < 500000 ; i++) {
            memset(node[i].nxt, 0, sizeof(node[i].nxt));
            node[i].fail = 0;
        }
        sz = 1;
    }
    void insert(string s, int num) {
        int n = s.size();
        int now = 0;
        for (int i = 0 ; i < n ; i++) {
            char c = s[i];
            if (!node[now].nxt[c - 'a']) {
                node[now].nxt[c - 'a'] = sz++;
            }
            now = node[now].nxt[c - 'a'];
        }
        node[now].cnt.pb(num);
    }
    void build() {
        node[0].fail = -1;
        queue<int>q;
        q.push(0);
        while (q.size()) {
            auto now = q.front();
            q.pop();
            for (int i = 0 ; i < 26 ; i++) {
                if (node[now].nxt[i]) {
                    if (now == 0) {
                        node[node[now].nxt[i]].fail = 0;
                    }
                    else {
                        int v = node[now].fail;
                        while (v != -1) {
                           if (node[v].nxt[i]) {
                            node[node[now].nxt[i]].fail = node[v].nxt[i];
                            break;
                           }
                           v = node[v].fail;
                        }
                        if (v == -1) {
                            node[node[now].nxt[i]].fail = 0;
                        }
                    }
                    q.push(node[now].nxt[i]);
                }
            }
        }
    }
    void match(string s) {
        int now = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            int c = s[i] - 'a';
            if (node[now].nxt[c]) {
                now = node[now].nxt[c];
            }
            else {
                int p = node[now].fail;
                while (p != -1 && node[p].nxt[c] == 0) {
                    p = node[p].fail;
                }
                if (p == -1) {
                    now = 0;
                }
                else {
                    now = node[p].nxt[c];
                }
            }
            int a = now;
            while (a) {
                if (node[a].cnt.size() && ans[node[a].cnt[0]]) break;
                for (auto &i : node[a].cnt)
                    ans[i] = 1;
                a = node[a].fail;
            }
        }
    }
}ac;
void solve() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    ac.init();
    f1(n) {
        string s;
        cin >> s;
        ac.insert(s, i);
    }
    ac.build();
    ac.match(str);
    f1(n) {
        if (ans[i]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
