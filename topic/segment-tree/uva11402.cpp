#include<iostream>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
const int maxn = 1048576;
const int mod = 998244353;
string s;
ll lz[maxn<<2];
ll cnt[maxn<<2];
void pushdown(int x, int l, int r){
    if(!lz[x])return ;
    int mid = (l + r) >> 1;
    if (lz[x] == 1) {
        lz[x<<1] = 1;
        lz[x<<1|1] = 1;
        cnt[x<<1] = 0;
        cnt[x<<1|1] = 0;
    }
    else if (lz[x] == 2) {
        lz[x<<1] = 2;
        lz[x<<1|1] = 2;
        cnt[x<<1] = mid - l + 1;
        cnt[x<<1|1] = r - mid;
    }
    else {
        if (!lz[x<<1]) {
            lz[x<<1] = 3;
        }
        else if (lz[x<<1] == 1) {
            lz[x<<1] = 2;
        }
        else if (lz[x<<1] == 2) {
            lz[x<<1] = 1;
        }
        else {
            lz[x<<1] = 0;
        }
        cnt[x<<1] = mid - l + 1 - cnt[x<<1];
        if (!lz[x<<1|1]) {
            lz[x<<1|1] = 3;
        }
        else if (lz[x<<1|1] == 1) {
            lz[x<<1|1] = 2;
        }
        else if (lz[x<<1|1] == 2) {
            lz[x<<1|1] = 1;
        }
        else {
            lz[x<<1|1] = 0;
        }
        cnt[x<<1|1] = r - mid - cnt[x<<1|1];
    }
    lz[x] = 0;
}
void pushup(int x){
    cnt[x] = cnt[x<<1] + cnt[x<<1|1];
}
void build(int x,int l,int r){
    lz[x] = cnt[x] = 0;
    if(l==r){
        if (s[l] == '1') {
            cnt[x] = 1;
        }
        else {
            cnt[x] = 0;
        }
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int ql,int qr, int op){
    if(ql <= l&&qr >= r){
        if (op <= 2) {
            if (op == 1) {
                cnt[x] = 0;
                lz[x] = 1;
            }
            else if (op == 2) {
                cnt[x] = r - l + 1;
                lz[x] = 2;
            }
        }
        else {
            if (lz[x] == 1) {
                lz[x] = 2;
            }
            else if (lz[x] == 2) {
                lz[x] = 1;
            }
            else if (lz[x] == 3) {
                lz[x] = 0;
            }
            else {
                lz[x] = 3;
            }
            cnt[x] = r - l + 1 - cnt[x];
        }
        return;
    }
    pushdown(x, l, r);
    int mid = (l+r) >> 1;
    if(ql <= mid){
        update(x<<1, l, mid, ql, qr, op);
    }
    if(qr > mid){
        update(x<<1|1, mid + 1, r, ql, qr, op);
    }
    pushup(x);
}
int query(int x,int l,int r,int ql,int qr){
    if(ql <= l&&qr >= r){
        //cout << l <<' '<<r<<' '<<cnt[x] << ' ' << lz[x] << endl;
        return cnt[x];
    }
    pushdown(x, l, r);
    int mid = (l+r) >> 1;
    int ret = 0;
    if(ql <= mid){
        ret += query(x<<1, l, mid, ql, qr);
    }
    if(qr > mid){
        ret += query(x<<1|1, mid + 1, r, ql, qr);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        int qc = 0;
        c++;
        cout << "Case "<<c<<":\n";
        s = "";
        int k;
        cin >> k;
        f (k) {
            int cnt;
            string ss;
            cin >> cnt >> ss;
            fr(j,0,cnt) {
               s += ss;
            }
        }
        //s = " " + s;
        //cout << s << endl;
        build(1,0,s.size() - 1);
        int q;
        cin >> q;
        while (q--) {
            char c;
            cin >> c;
            int l, r;
            cin >> l >> r;
            if (c == 'F') {
                update(1,0,s.size()-1,l,r,2);
            }
            else if (c == 'E') {
                update(1,0,s.size()-1,l,r,1);
            }
            else if (c == 'I') {
                update(1,0,s.size()-1,l,r,3);
            }
            else {
                qc++;
                cout << 'Q'<<qc<<": ";
                cout << query(1,0,s.size()-1,l,r) << '\n';
            }
        }
    }
}
