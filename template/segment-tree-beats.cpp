// Segment Tree Beats (Ji Driver Segment Tree)
// Range min, Range sum
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MAXN = 1000005;
long long mx[MAXN<<2];
long long cmx[MAXN<<2];
long long sec[MAXN<<2];
long long sum[MAXN<<2];
void pushup(int x) {
	sum[x] = sum[x<<1] + sum[x<<1|1];
	if (mx[x<<1] > mx[x<<1|1]) {
		mx[x] = mx[x<<1];
		cmx[x] = cmx[x<<1];
		sec[x] = max(mx[x<<1|1],sec[x<<1]);
	}
	else if (mx[x<<1] < mx[x<<1|1]) {
		mx[x] = mx[x<<1|1];
		cmx[x] = cmx[x<<1|1];
		sec[x] = max(mx[x<<1],sec[x<<1|1]);
	}
	else {
		mx[x] = mx[x<<1|1];
		cmx[x] = cmx[x<<1|1] + cmx[x<<1];
		sec[x] = max(sec[x<<1|1],sec[x<<1]);
	}
}
void pushdown(int x) {
	if (mx[x] < mx[x<<1]) {
		sum[x<<1] -= cmx[x<<1] * (mx[x<<1] - mx[x]);
		mx[x<<1] = mx[x];
	}
	if (mx[x] < mx[x<<1|1]) {
		sum[x<<1|1] -= cmx[x<<1|1] * (mx[x<<1|1] - mx[x]);
		mx[x<<1|1] = mx[x];
	}
}
void build(int x, int l, int r) {
	if (l == r) {
		cin >> sum[x];
		mx[x] = sum[x];
		cmx[x] = 1;
		sec[x] = -1e5;
		return;
	}
	int mid = (l + r) >> 1;
	build(x<<1, l, mid);
	build(x<<1|1, mid + 1, r);
	pushup(x);
}
void update(int x, int l, int r,int ql, int qr, int val) {
	if (mx[x] <= val) {
		return;
	}
	if (ql <= l && qr >= r && val > sec[x]) {
		sum[x] -= (mx[x] - val) * cmx[x];
		mx[x] = val;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if (ql <= mid) {
		update(x<<1, l, mid, ql, qr, val);
	}
	if (qr > mid) {
		update(x<<1|1, mid + 1, r, ql, qr, val);
	}
	pushup(x);
}
long long query(int x, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return sum[x];
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if (qr <= mid) {
		return query(x<<1,l,mid,ql,qr);
	}
	else if (ql > mid) {
		return query(x<<1|1,mid+1,r,ql,qr);
	}
	else {
		return query(x<<1,l, mid,ql,qr) + query(x<<1|1,mid+1,r,ql,qr);
	}
}
long long query2(int x, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) {
		return mx[x];
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if (qr <= mid) {
		return query2(x<<1,l,mid,ql,qr);
	}
	else if (ql > mid) {
		return query2(x<<1|1,mid+1,r,ql,qr);
	}
	else {
		return max(query2(x<<1,l, mid,ql,qr), query2(x<<1|1,mid+1,r,ql,qr));
	}
}
void go() {
	int n, q;
	cin >> n >> q;
	build(1,1,n);
	while (q--) {
		int op, l, r, v;
		cin >> op >> l >> r;
		if (op == 0) {
			cin >> v;
			update(1,1,n,l,r,v);
		}
		else if (op == 1) {
			cout << query2(1,1,n,l,r) << '\n';
		}
		else {
			cout << query(1,1,n,l,r) << '\n';
		}
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
