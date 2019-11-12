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
map<int,int>mp;
bool cmp(pair<int,int>x,pair<int,int>y){
    if(x.S!=y.S){
        return x.S < y.S;
    }
    else{
        return x.F > y.F;
    }
}
int mx[maxn<<2];
int lz[maxn<<2];
void pushup(int x){
    mx[x] = max(mx[x<<1],mx[x<<1|1]);
}
void pushdown(int x){
    if(!lz[x])return ;
    mx[x<<1] += lz[x];
    mx[x<<1|1] += lz[x];
    lz[x<<1] += lz[x];
    lz[x<<1|1] += lz[x];
    lz[x] = 0;
}
void update(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        mx[x]++;
        lz[x]++;
        return ;
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(ql <= mid){
        update(x<<1,l,mid,ql,qr);
    }
    if(qr > mid){
        update(x<<1|1,mid+1,r,ql,qr);
    }
    pushup(x);
}
int query(int x,int l,int r,int ql,int qr){
    if(ql <= l && qr >= r){
        return mx[x];
    }
    pushdown(x);
    int mid = (l + r) >> 1;
    int ret = 0;
    if(ql <= mid){
        ret = max(ret,query(x<<1,l,mid,ql,qr));
    }
    if(qr > mid){
        ret = max(ret,query(x<<1|1,mid+1,r,ql,qr));
    }
    pushup(x);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int,int> >v;
    f(n){
        int add1, add2;
        cin >> add1 >> add2;
        add2--;
        mp[add1];
        mp[add2];
        v.pb({add1,add2});
    }
    sort(v.begin(),v.end(),cmp);
    int idx = 0;
    for(auto &i : mp){
        i.S = ++idx;
    }
    for(auto &i:v){
        i.F = mp[i.F];
        i.S = mp[i.S];
    }
    int ans = 0;
    for(auto i:v){
       // cout << idx <<' '<<i.F<<' '<<i.S<<endl;
        int m = query(1,1,idx,i.F,i.S);
        //cout << m << endl;
        if (m < k){
            ans++;
            update(1,1,idx,i.F,i.S);
        }
    }
    cout << ans << endl;
}
