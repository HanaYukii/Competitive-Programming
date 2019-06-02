#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
typedef pair<pii, pii> pp;
const double eps = 1e-8;
double dist(pii &a, pii& b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}
LL cross(pii &o, pii &a, pii &b) {
    return (a.F - o.F) * (b.S - o.S) - (a.S - o.S) * (b.F - o.F);
}
double dist(pp &a, pp &b) {
    double sum = dist(a.F, a.S) + dist(b.F, b.S);
    if (a.F < a.S) swap(a.F, a.S);
    if (b.F < b.S) swap(b.F, b.S);
    LL area = abs(cross(a.F, b.F, b.S)) + abs(cross(b.S, a.F, a.S));
    return (double)area / sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<pii, vector<pp> > pool;
    for (int i = 0 ; i < n ; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int dx = x1 - x2;
        int dy = y1 - y2;
        if (dx == 0) {
            dy = 1; 
        } else if (dy == 0) {
            dx = 1;
        } else if (dx < 0) {
            dx *= -1, dy *= -1;
        }
        LL g = __gcd(abs(dx), abs(dy));
        dx /= g, dy /= g;
        pool[{dx, dy}].push_back({{x1, y1}, {x2, y2}});
    }
    LL ans = 0;
    for (auto &p : pool) {
        pii rev = {p.F.S, -p.F.F};
        if (rev.F == 0) {
            rev.S = 1;
        } else if (rev.F < 0)
            rev.F *= -1, rev.S *= -1;
        if (pool.count(rev)) {
            vector<pp> tar = pool[rev];
            vector<double> dists_a, dists_b;
            for (int i = 0 ; i < (int)tar.size() ; i++)
                for (int j = i + 1 ; j < (int)tar.size() ; j++)
                    dists_a.push_back(dist(tar[i], tar[j]));
            sort(dists_a.begin(), dists_a.end());
            for (int i = 0 ; i < (int)p.S.size() ; i++)
                for (int j = i + 1 ; j < (int)p.S.size() ; j++)
                    dists_b.push_back(dist(p.S[i], p.S[j]));
            sort(dists_b.begin(), dists_b.end());
            for (int i = 0 ; i < dists_b.size() ; i++) {
                ans += upper_bound(dists_a.begin(), dists_a.end(), dists_b[i] + eps) - lower_bound(dists_a.begin(), dists_a.end(), dists_b[i] - eps);
            }
        }
    }
    cout << ans / 2 << '\n';
}