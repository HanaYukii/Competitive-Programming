#include<bits/stdc++.h>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
const int mod = 1e9+7;
const int maxn = 200005;
int idx[maxn<<2];
int mx[maxn<<2];
int val[maxn];
vector<int>bit[30];
ll ans;
int n;
void pushup(int x){
    if(mx[x<<1]>mx[x<<1|1]){
        mx[x] = mx[x<<1];
        idx[x] = idx[x<<1];
    }
    else{
        mx[x] = mx[x<<1|1];
        idx[x] = idx[x<<1|1];
    }
}
void build(int x,int l,int r){
    if(l==r){
        cin >> mx[x];
        idx[x] = l;
        val[l] = mx[x];
        for(int i=29;i>=0;i--){
            if(val[l]&(1<<i)){
                bit[i].pb(l);
            }
        }
        return ;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
pair<int,int> query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return {mx[x],idx[x]};
    }
    pair<int,int>ret;
    int mid = (l+r) >> 1;
    if(ql<=mid){
        pair<int,int>tmp = query(x<<1,l,mid,ql,qr);
        if(tmp.F>=ret.F){
            ret = tmp;
        }
    }
    if(qr>mid){
        pair<int,int>tmp = query(x<<1|1,mid+1,r,ql,qr);
        if(tmp.F>=ret.F){
            ret = tmp;
        }
    }
    return ret;
}
void solve(int l,int r){
    if(l>r)return;
    int mid = query(1,1,n,l,r).S;
    //cout<<l<<' '<<r<<' '<<mid<<endl;
    int L = l - 1;
    int R = r + 1;
    for(int i=29;i>=0;i--){
        if(val[mid]&(1<<i))continue;
        if(lower_bound(bit[i].begin(),bit[i].end(),mid)!=bit[i].end()){
            R = min(R,*lower_bound(bit[i].begin(),bit[i].end(),mid));
        }
        if(lower_bound(bit[i].begin(),bit[i].end(),mid)!=bit[i].begin()){
            L = max(L,*(--lower_bound(bit[i].begin(),bit[i].end(),mid)));
        }
    }
    ans -= (ll)(mid - L) * (R - mid);
    solve(l,mid-1);
    solve(mid+1,r);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n){
        build(1,1,n);
        ans = (ll)n * (n+1) / 2;
        solve(1,n);
        cout << ans << endl;
    }
}