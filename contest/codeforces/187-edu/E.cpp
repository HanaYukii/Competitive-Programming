#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;
int n;
int lg;
long long cnt[MAXN << 1];
void cnt_upd(int i) { 
    while (i <= n) {
        cnt[i]++;
        i += i & -i;
    }
}

int kth(int k) {
    int pos = 0;
    for (int b = lg; b >= 0; b--) {
        int npos = pos + (1 << b);
        if (npos <= n && cnt[npos] < k) {
            pos = npos;
            k -= cnt[npos];
        }
    }
    return pos + 1;
}

long long sum[MAXN << 1];
void sum_upd(int x, long long v) { 
    while (x <= n) {
        sum[x] += v;
        x += x & -x;
    }
}
long long query(int x) { 
    long long s = 0; 
    while (x) {
        s += sum[x];
        x -= x & -x;
    }
    return s; 
}

vector<long long> d;
long long tot;


long long pm(long long x, long long y) {
    long long ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int get_rank(long long x) {
    return lower_bound(d.begin(), d.end(), x) - d.begin() + 1;
}

void solve() {
    cin >> n;
    lg = __lg(n);
    vector<long long> a(n);
    d.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d.push_back(a[i]);
    }
    sort(d.begin(), d.end());
    tot = 0;
    for (int i = 0; i < n; i++) {
        int rk = get_rank(a[i]);
        cnt_upd(rk);
        sum_upd(rk, a[i]);
        tot += a[i];
        int sz = i + 1;
        if (sz < 3) continue;
        int l = 1, r = sz;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int rkr = kth(mid + 1);
            long long rsum = tot - query(rkr) - (long long)(sz - mid - 1) * d[rkr - 1];
            long long lsum = 0;
            if (mid > 2) {
                int rkl = kth(mid - 1);
                int rks = kth(mid - 2);
                lsum = (long long)(mid - 2) * d[rkl - 1] - query(rks);
            }
            if (rsum >= lsum) l = mid;
            else r = mid;
        }
        int rk1 = kth(l + 1);
        long long ansr = tot - query(rk1) - (long long)(sz - l - 1) * d[rk1 - 1];

        long long ansl = 0;
        if (l + 1 > 2) {
            int rkv = kth(l);
            int rks = kth(l - 1);
            ansl = (long long)(l - 1) * d[rkv - 1] - query(rks);
        }

        long long ans_num = min(ansr, ansl);
        long long ans = (ans_num % MOD + MOD) % MOD * pm(sz - 2, MOD - 2) % MOD;
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
