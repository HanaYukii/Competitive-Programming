// Contest default template
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll mod = 998244353;

struct mat {
    int n;
    vector<vector<ll>> a;
    mat(int n) : n(n), a(n, vector<ll>(n, 0)) {
    }

    static mat I(int n) {
        mat r(n);
        for (int i = 0; i < n; i++)
            r.a[i][i] = 1;
        return r;
    }

    mat operator*(const mat& b) const {
        mat r(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!a[i][k])
                    continue;
                ll aik = a[i][k];
                for (int j = 0; j < n; j++) {
                    r.a[i][j] = (r.a[i][j] + aik * b.a[k][j]) % mod;
                }
            }
        }
        return r;
    }

    mat operator+(const mat& b) const {
        mat r(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                r.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
        return r;
    }

    mat pow(ll p) const {
        mat r = I(n), base = *this;
        while (p) {
            if (p & 1)
                r = r * base;
            base = base * base;
            p >>= 1;
        }
        return r;
    }
};

vector<string> str;
vector<string> states;
unordered_map<string, int> id;

void getpre() {
    set<string> s;
    s.insert("");
    for (auto& p : str) {
        for (int i = 1; i < (int)p.size(); i++) {
            s.insert(p.substr(0, i));
        }
    }
    for (auto& t : s) {
        states.push_back(t);
    }
    for (int i = 0; i < (int)states.size(); i++) {
        id[states[i]] = i;
    }
}

bool contain(const string& t) {
    for (auto& p : str) {
        if (t.find(p) != string::npos)
            return true;
    }
    return false;
}

int suffix(const string& t) {
    for (int len = (int)t.size(); len >= 0; len--) {
        string suf = t.substr((int)t.size() - len);
        auto it = id.find(suf);
        if (it != id.end())
            return it->second;
    }
    return 0;
}

mat build() {
    int sz = states.size();
    mat res(sz);
    for (int u = 0; u < sz; u++) {
        for (int c = 0; c < 26; c++) {
            string t = states[u] + char('a' + c);
            if (contain(t))
                continue;
            int v = suffix(t);
            res.a[u][v]++;
        }
    }
    return res;
}

void solve() {
    ll n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    getpre();
    mat m = build();
    mat res = m.pow(n);
    ll ans = 0;
    for (int i = 0; i < (int)states.size(); i++) {
        ans = (ans + res.a[id[""]][i]) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
