#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;
ll lz[maxn<<2];
ll mx[maxn<<2];
ll c[maxn];
ll v[maxn];
ll zz[maxn];
ll cur;
void pushdown(int x){
    if(!lz[x])return ;
    lz[x<<1] += lz[x];
    lz[x<<1|1] += lz[x];
    mx[x<<1] += lz[x];
    mx[x<<1|1] += lz[x];
    lz[x] = 0;
}
void pushup(int x){
    mx[x] = min(mx[x<<1], mx[x<<1|1]);
}
void build(int x,int l,int r){
    if(l==r){
        cur += zz[l];
        mx[x] = cur;
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int ql,int qr,ll v){
    if(ql <= l&&qr >= r){
        mx[x] += v;
        lz[x] += v;
        return ;
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(ql <= mid){
        update(x<<1, l, mid, ql, qr, v);
    }
    if(qr > mid){
        update(x<<1|1, mid + 1, r, ql, qr, v);
    }
    pushup(x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 1e18;
    cur = 0;
    f1(n){
        cin >> v[i];
    }
    f1(n){
        cin >> c[i];
        zz[v[i]] = c[i];
    }
    build(1,0,n);
    for(int i = 1 ; i < n ; i++){
        update(1,0,n,0,v[i]-1,c[i]);
        update(1,0,n,v[i],n,-c[i]);
        //cout << mx[1] << '\n';
        ans = min(ans,mx[1]);
    }
    cout << ans << '\n';
}
