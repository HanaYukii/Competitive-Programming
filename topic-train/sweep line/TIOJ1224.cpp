#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
struct s{
    int x;
    int l,r,del;
};
bool cmp(s x,s y){
    return x.x < y.x;
}
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
    int n;
    cin >> n;
    vector<s>v;
    ll ans = 0;
    f(n){
        int l, r, u, d;
        cin >> l >> r >> u >> d;
        l++;
        v.pb({u,l,r,1});
        v.pb({d,l,r,-1});
    }
    sort(v.begin(),v.end(),cmp);
    int last = 0;
    for(auto i:v){
        ans += (ll)(i.x - last) * tot[1];
        update(1,1,maxn-5,i.l,i.r,i.del);
        last = i.x;
    }
    cout << ans << endl;
}
