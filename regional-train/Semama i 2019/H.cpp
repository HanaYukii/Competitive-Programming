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
const int mod = 1e9 + 7;
ll v[maxn<<2];
ll lz[maxn<<2];
int val[maxn];
int del[maxn];
void pushdown(int x){
    if(!lz[x])return;
    lz[x<<1] += lz[x];
    lz[x<<1] %= mod;
    lz[x<<1|1] += lz[x];
    lz[x<<1|1] %= mod;
    v[x<<1] += lz[x];
    v[x<<1] %= mod;
    v[x<<1|1] += lz[x];
    v[x<<1|1] %= mod;
    lz[x] = 0;
}
void pushup(int x){
    v[x] = (v[x<<1] + v[x<<1|1]) % mod;
}
void update(int x,int l,int r,int ql,int qr,int del){
    if(ql <= l && qr >= r){
        v[x] += del;
        v[x] %= mod;
        lz[x] += del;
        lz[x] %= mod;
        return;
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if(ql <= mid){
        update(x<<1,l,mid,ql,qr,del);
    }
    if(qr > mid){
        update(x<<1|1,mid+1,r,ql,qr,del);
    }
    pushup(x);
}
ll query(int x,int l,int r,int q){
    if(l==r){
        return v[x];
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    if(q <= mid){
        return query(x<<1,l,mid,q);
    }
    else{
        return query(x<<1|1,mid+1,r,q);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int>vv;
    f1(n-1)cin >> val[i];
    f1(n-1)cin >> del[i];
    ll sum = 0;
    f1(n-1){
        sum += val[i];
        if(val[i]){
            vv.pb(i);
        }
    }
    vv.pb(n+1);
    update(1,1,n,1,1,1);
    f1(n-1){
        int nxt = min(min(*upper_bound(vv.begin(),vv.end(),i),i+del[i]),n);
        update(1,1,n,i+1,nxt,query(1,1,n,i));
    }

    cout << sum <<' ' << query(1,1,n,n) << endl;
}
