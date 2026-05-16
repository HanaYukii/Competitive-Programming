#include <bits/stdc++.h>
using namespace std;
long long ans;
vector<int> d;
string s;
long long num;

void shorter() {
    int len = (int)s.size() - 1;
    if (len <= 0)
        return;
    long long x = 0;
    for (int i = 0; i < len; i++) {
        x = x * 10 + d.back();
    }
    ans = min(ans, num - x);
}

void longer() {
    if (s.size() >= 18)
        return;
    int len = (int)s.size() + 1;
    long long x = 0;
    int use = -1;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] != 0) {
            use = d[i];
            break;
        }
    }
    if (use == -1)
        return;
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            x = use;
        } else {
            x = x * 10 + d[0];
        }
    }
    ans = min(ans, x - num);
}

void big_same() {
    int len = (int)s.size();
    int mx = d.back();
    long long cur = 0;
    vector<int> use;
    for (int i = 0; i < len; i++) {
        int lim = s[i] - '0';
        int nx = -1;
        for (int j = d.size() - 1; j >= 0; j--) {
            int x = d[j];
            if (i == 0 && len > 1 && x == 0)
                continue;
            if (x <= lim) {
                nx = x;
                break;
            }
        }
        if (nx != -1) {
            use.push_back(nx);
            cur = cur * 10 + nx;
            if (nx < lim) {
                // fill the rest with the max digit
                for (int k = i + 1; k < len; k++) {
                    cur = cur * 10 + mx;
                }
                ans = min(ans, abs(num - cur));
                return;
            }
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            int pre = use[j];
            int nxt = -1;
            for (int k = d.size() - 1; k >= 0; k--) {
                int x = d[k];
                if (j == 0 && len > 1 && x == 0)
                    continue;
                if (x < pre) {
                    nxt = x;
                    break;
                }
            }
            if (nxt != -1) {
                long long val = 0;
                for (int k = 0; k < j; k++) {
                    val = val * 10 + use[k];
                }
                val = val * 10 + nxt;
                // fill the rest with the max digit
                for (int k = j + 1; k < len; k++) {
                    val = val * 10 + mx;
                }
                ans = min(ans, abs(num - val));
                return;
            }
        }
        return;
    }
    ans = min(ans, abs(num - cur));
}

void small_same() {
    int len = (int)s.size();
    int mn = d[0];
    long long cur = 0;
    vector<int> use;
    for (int i = 0; i < len; i++) {
        int lim = s[i] - '0';
        int nx = -1;
        for (int j = 0; j < d.size(); j++) {
            int x = d[j];
            if (i == 0 && len > 1 && x == 0)
                continue;
            if (x >= lim) {
                nx = x;
                break;
            }
        }
        if (nx != -1) {
            use.push_back(nx);
            cur = cur * 10 + nx;
            if (nx > lim) {
                // fill the rest with the min digit
                for (int k = i + 1; k < len; k++) {
                    cur = cur * 10 + mn;
                }
                ans = min(ans, abs(num - cur));
                return;
            }
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            int pre = use[j];
            int nxt = -1;
            for (int k = 0; k < d.size(); k++) {
                int x = d[k];
                if (j == 0 && len > 1 && x == 0)
                    continue;
                if (x > pre) {
                    nxt = x;
                    break;
                }
            }
            if (nxt != -1) {
                long long val = 0;
                for (int k = 0; k < j; k++) {
                    val = val * 10 + use[k];
                }
                val = val * 10 + nxt;
                // fill the rest with the min digit
                for (int k = j + 1; k < len; k++) {
                    val = val * 10 + mn;
                }
                ans = min(ans, abs(num - val));
                return;
            }
        }
        return;
    }
    ans = min(ans, abs(num - cur));
}

void solve() {
    cin >> s;
    int n;
    cin >> n;
    d.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    if (d.size() == 1 && d[0] == 0) {
        cout << s << endl;
        return;
    }
    num = stoll(s);
    ans = LLONG_MAX;
    big_same();
    small_same();
    shorter();
    longer();

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}
