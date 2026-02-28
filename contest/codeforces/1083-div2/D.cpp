#include <bits/stdc++.h>
using namespace std;

int a[500005];

int cal(int left, int right) {
    if (left > right) 
        return 0;
    int sz = right - left + 1;
    vector<int> l(sz, 1);
    vector<int> r(sz, 1);
    vector<int> v;
    for (int i = left; i <= right; i++) {
        while (v.size() && a[v.back()] <= a[i]) {
            v.pop_back();
        }
        if (v.size()) {
            l[i - left] = l[v.back() - left] + 1;
        }
        v.push_back(i);
    }
    v.clear();
    for (int i = right; i >= left; i--) {
        while (v.size() && a[v.back()] <= a[i]) {
            v.pop_back();
        }
        if (v.size()) {
            r[i - left] = r[v.back() - left] + 1;
        }
        v.push_back(i);
    }
    int mx = 0;
    for (int i = 0; i < sz; i++) {
        mx = max(mx, l[i] + r[i]);
    }
    return mx;
}

void solve() {
    int n;
    cin >> n;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == n) {
            pos = i;
        }
    }
    int best = max(cal(0, pos - 1), cal(pos + 1, n - 1));
    cout << n - best << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
