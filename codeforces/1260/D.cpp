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
struct s{
    int l,r,v;
};
int cnt[maxn<<2];
int tot[maxn<<2];
void pushup(int x,int l,int r){
    if(cnt[x]){
        tot[x] = r - l + 1;
    }
    else{
        if(r - l){
            tot[x] = tot[x<<1] + tot[x<<1|1];
        }
        else{
            tot[x] = 0;
        }
    }
}
void update(int x,int l,int r,int ql,int qr,int del){
    if(ql <= l && qr >= r){
        cnt[x] += del;
        pushup(x,l,r);
        return;
    }
    int mid = (l+r) >> 1;
    if(ql <= mid){
        update(x<<1,l,mid,ql,qr,del);
    }
    if(qr > mid){
        update(x<<1|1,mid+1,r,ql,qr,del);
    }
    pushup(x,l,r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, mm, k, t;
    cin >> n >> mm >> k >> t;
    vector<int>v(n);
    for(auto &i:v){
        cin >> i;
    }
    sort(v.rbegin(),v.rend());
    vector<s>vv(k);
    for(auto &i:vv){
        cin >> i.l >> i.r >> i.v;
    }
    int l = -1, r = n;
    while(l < r - 1){
        int m = (l + r) >> 1;
        int tar = v[m];
        //int mxb = -1,mib = 1e9;
        memset(tot,0,sizeof(tot));
        memset(cnt,0,sizeof(cnt));
        for(auto j:vv){
            if(j.v > tar){
                update(1,1,200000,j.l,j.r,1);
            }
        }
        ll sum = mm + 1;
        //if(~mxb){
            sum += (tot[1]) * 2;
        //}
        if(sum <= t){
            l = m;
        }
        else{
            r = m;
        }
    }
    cout << l + 1 << '\n';
}
