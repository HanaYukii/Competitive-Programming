// CDQ divide and conquer
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
const int maxn = 1000005;
const int mod = 998244353;
int k;
struct s
{
    int x, y, z;
    int cnt, ans, id;
};
vector<s>v;
int b[maxn];
void update(int x, int d) {
    while (x <= 100000) {
        b[x] += d;
        x += x & (-x);
    }
}
int query(int x) {
    int ret = 0;
    while (x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
bool cmp(s x, s y) {
    if (x.x != y.x) {
        return x.x < y.x;
    }
    if (x.y != y.y) {
        return x.y < y.y;
    }
    return x.z < y.z;
}
bool cmp2(s x, s y) {
    if (x.y != y.y) {
        return x.y < y.y;
    }
    return x.z < y.z;
}
void cdq(int l, int r) {
    if (l == r) {
        v[l].ans += v[l].cnt - 1;
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    sort(v.begin()+l, v.begin() + mid + 1, cmp2);
    sort(v.begin() + mid + 1, v.begin() + r + 1, cmp2);
    int ptr = l;
    for (int i = mid + 1 ; i <= r; i++) {
        while (ptr <= mid && v[ptr].y <= v[i].y) {
            update(v[ptr].z,v[ptr].cnt);
            ptr++;
        }
        v[i].ans += query(v[i].z);
    }
    for (int i = l ; i < ptr; i++) {
        update(v[i].z, -v[i].cnt);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int n;
        cin >> n;
        f (n) {
            int x, y, z;
            cin >> x >> y >> z;
            v.pb({x,y,z,1,0,i});
        }
        sort(all(v), cmp);
        
        cdq(0, v.size() - 1);
        vector<int>ans(n,0);
        for (auto i= n - 1 ; i >= 0 ; i--) {
            if (i + 1 < n && v[i].x == v[i+1].x && v[i].y == v[i+1].y && v[i].z == v[i+1].z) {
                ans[v[i].id] = ans[v[i+1].id];
            }
            else {
                ans[v[i].id] = v[i].ans;
            }
        }
        for (auto i:ans) {
            cout << i << '\n';
        }
    }
}
