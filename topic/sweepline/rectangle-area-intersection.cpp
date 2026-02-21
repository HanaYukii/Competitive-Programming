
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e6+5;
vector<double>di;
int cnt[MAXN];
double sum1[MAXN], sum2[MAXN];
void pull(int x,int l,int r) {
    if (cnt[x] >= 2) {
        sum2[x] = di[r] - di[l - 1];
    }
    else if (cnt[x] == 1) {
        if (r - l)
            sum2[x] = sum1[x<<1] + sum1[x<<1|1];
        else
            sum2[x] = 0;
    }
    else {
        if (r - l)
            sum2[x] = sum2[x<<1] + sum2[x<<1|1];
        else
            sum2[x] = 0;
    }
    if (cnt[x] >= 1) {
        sum1[x] = di[r] - di[l - 1];
    }
    else {
        if (r - l)
            sum1[x] = sum1[x<<1] + sum1[x<<1|1];
        else
            sum1[x] = 0;
    }
}
void update(int x,int l,int r,int ql, int qr, int d) {
    if (ql <= l && qr >= r) {
        cnt[x]+=d;
        pull(x,l,r);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        update(x<<1,l,mid,ql,qr,d);
    }
    if (qr > mid) {
        update(x<<1|1,mid+1,r,ql,qr,d);
    }
    pull(x,l,r);
}
void go() {
    int n;
    cin >> n;
    vector<tuple<double,double,double,int>>v;
    di.clear();
    for (int i = 0 ; i < n ; i++) {
        double l, u, r, d;
        cin >> l >> u >> r >> d;
        di.push_back(l);
        di.push_back(r);
        v.push_back(make_tuple(u, l, r, 1));
        v.push_back(make_tuple(d, l, r, -1));
    }
    sort((di).begin(), (di).end());
    di.erase(unique((di).begin(), (di).end()),di.end());
    sort((v).begin(), (v).end());
    double last = 0;
    double ans = 0;
    for (auto &i : v) {
        int l = lower_bound((di).begin(), (di).end(),get<1>(i)) - di.begin() + 1;
        int r = lower_bound((di).begin(), (di).end(),get<2>(i)) - di.begin();
        //cout << get<1>(i) <<' '<<get<2>(i) << endl;
        ans += sum2[1] * (get<0>(i) - last);
        last = get<0>(i);
        update(1,1,di.size() - 1, l, r, get<3>(i));
        //cout << l <<' '<<r<<' '<<get<3>(i)<<endl;
    }
    printf("%.2f\n", ans);
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int c = 1;
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
