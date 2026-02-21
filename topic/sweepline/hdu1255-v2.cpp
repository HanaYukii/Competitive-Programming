#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<ctime>
const double EPS = 1e-6;
using LL = long long;
using pii = pair<int, int>;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int MAXN = 2100;
//const int INF = 0x3f3f3f3f;
struct Node {
	int l, r, c;
	double lf, rf, cnt, dcnt;
} segTree[MAXN*4];
struct Line {
	int c;
	double x, y1, y2;
	bool operator < (const Line& E) const {
		return x < E.x;
	}
} line[MAXN];
double y[MAXN];
void build(int o, int L, int R) {
	Node& t = segTree[o];
	t.l = L;
	t.r = R;
	t.c = 0;
	t.lf = y[L];
	t.rf = y[R];
	t.cnt = 0;
	t.dcnt = 0;
	if(L+1 == R) return;
	int M =  (L+R) >> 1;
	build(o<<1, L, M);
	build((o<<1)|1, M, R);
}
void cal(int o) {
	Node& t = segTree[o];
	if(t.c > 1) {
		t.dcnt = t.cnt = t.rf - t.lf;
	}
	else if(t.c == 1) {
		t.cnt = t.rf - t.lf;
		if(t.l+1 == t.r) t.dcnt = 0;
		else t.dcnt = segTree[o<<1].cnt + segTree[(o<<1)|1].cnt;
	}
	else {
		if(t.l+1 == t.r) t.dcnt = t.cnt = 0;
		else t.dcnt = segTree[o<<1].dcnt + segTree[(o<<1)|1].dcnt, t.cnt = segTree[o<<1].cnt + segTree[(o<<1)|1].cnt;
	}
}
void update(int o, Line e) {
	Node& t = segTree[o];
	if(e.y1==t.lf && e.y2==t.rf) {
		t.c += e.c;
		cal(o);
		return;
	}
	if(e.y2 <= segTree[o<<1].rf) update(o<<1, e);
	else if(e.y1 >= segTree[(o<<1)|1].lf) update((o<<1)|1, e);
	else {
		Line tmp = e;
		tmp.y2 = segTree[o<<1].rf;
		update(o<<1, tmp);
		e.y1 = segTree[(o<<1)|1].lf;
		update((o<<1)|1, e);
	}
	cal(o);
}
int n, tot;
int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
	while(T--) {
		cin >> n;
		tot = 0;
		for(int i = 1; i <= n; i++) {
			double x1,x2,y1,y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			++tot;
			line[tot].y1 = y1;
			line[tot].y2 = y2;
			line[tot].x = x1;
			line[tot].c = 1;
			y[tot] = y1;
			++tot;
			line[tot].y1 = y1;
			line[tot].y2 = y2;
			line[tot].x = x2;
			line[tot].c = -1;
			y[tot] = y2;
		}
		sort(y+1, y+tot+1);
		sort(line+1, line+tot+1);
		build(1, 1, tot);
		double ans = 0;
		update(1, line[1]);
		for(int i = 2; i <= tot; i++) {
			ans += (line[i].x-line[i-1].x) * segTree[1].dcnt;
			update(1, line[i]);
		}
		printf("%.2f\n", ans);
	}
    return 0;
}
