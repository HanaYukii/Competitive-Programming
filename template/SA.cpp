// Suffix Array
// cses 2106
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 200005;
void count_sort(vector<int>&p, vector<int>&c) {
    int n = p.size();
    vector<int>cnt(n);
    for (auto &i : c) {
        cnt[i]++;
    }
    vector<int>p_new(n);
    vector<int>pre{0};
    for (auto &i : cnt) {
        pre.pb(pre.back() + i);
    }
    for (auto &i : p) {
        p_new[pre[c[i]]++] = i;
    }
    p = p_new;
}
void go() {
    int n;
    string s;
    cin >> s;
    s += '$';
    n = s.size();
    vector<int>c(n), p(n);
    {
        vector<pair<char,int>>a(n);
        for (int i = 0 ; i < n ; i++) {
            a[i] = {s[i], i};
        }
        sort(all(a));
        for (int i = 0 ; i < n ; i++) {
            p[i] = a[i].S;
        }
        c[p[0]] = 0;
        for (int i = 1 ; i < n ; i++) {
            if (a[i].F == a[i - 1].F) {
                c[p[i]] = c[p[i - 1]];
            }
            else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        for (int i = 0 ; i < n ; i++) {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);
        vector<int>c_new(n);
        c_new[p[0]] = 0;
        for (int i = 1 ; i < n ; i++) {
            pair<int,int> cur = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int,int> prev = {c[p[i-1]], c[(p[i - 1] + (1 << k)) % n]};
            if (cur == prev) {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    int lcp[s.size()] = {};
    k = 0;
    for (int i = 0 ; i < n - 1 ; i++) {
        int pos = c[i];
        int j = p[pos-1];
        while (s[i + k] == s[j + k]) {
            k++;
        }
        lcp[c[i]-1] = k;
        k = max(k - 1, 0);
    }
    int mx = 0;
    f((int)s.size() - 1) {
        if  (lcp[i] > lcp[mx]) {
            mx = i;
        }
    }
    if (lcp[mx] == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << s.substr(p[mx], lcp[mx]) << '\n';
    }
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
