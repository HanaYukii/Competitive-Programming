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
//#define int long long
const int mod = 1e9 + 7;
int mx[maxn<<2];
void pushup(int x){
    mx[x] = max(mx[x<<1],mx[x<<1|1]);
}
void build(int x,int l,int r){
    if(l==r){
        cin >> mx[x];
        mx[x]++;
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
int query(int x,int l,int r,int ql,int qr){
    if(ql <= l && qr >= r){
        return mx[x];
    }
    int mid = (l+r) >> 1;
    int ret = 0;
    if(ql <= mid){
        ret = query(x<<1,l,mid,ql,qr);
    }
    if(qr > mid){
        ret = max(ret,query(x<<1|1,mid+1,r,ql,qr));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m;
    int n;
    cin >> n >> m;
    int ans = 0;
    build(1,1,n);
    for(int i = 1 ; i<= 100000 ; i++){
        ll sum = 0;
        int cur = 1;
        while(cur <= n){
            sum += query(1,1,n,cur,cur+i-1);
            cur += i;
        }
        if(sum - 1 <= m){
            cout << i <<endl;
            exit(0);
        }
    }
}
