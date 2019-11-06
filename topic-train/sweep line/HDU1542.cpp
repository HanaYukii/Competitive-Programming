#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 2005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
struct s{
    double x;
    double L,R;
    int l,r,del;
};
bool cmp(s x,s y){
    return x.x < y.x;
}
int cnt[maxn<<2];
double tot[maxn<<2];
map<double,int>mp;
double pre[maxn];
int idx;
void init(){
    idx = 0;
    memset(pre,0,sizeof(pre));
    memset(tot,0,sizeof(tot));
    mp.clear();
    memset(cnt,0,sizeof(cnt));
}
void pushup(int x,int l,int r){
    if(cnt[x]){
        tot[x] = pre[r] - pre[l-1];
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
    int c = 0;
    while(cin >> n&&n){
    c++;
    init();
    vector<s>v;
    double ans = 0;
    f(n){
        double l, r, u, d;
        cin >> l >> u >> r >> d;
        v.pb({u,l,r,0,0,1});
        v.pb({d,l,r,0,0,-1});
        mp[l];
        mp[r];
    }   
    for(auto &i:mp){
        i.S = ++idx;
        pre[idx] = i.F;
    }
    for(auto &i:v){
        i.l = mp[i.L] + 1;
        i.r = mp[i.R];
    }
    sort(v.begin(),v.end(),cmp);
    double last = 0;
    for(auto i:v){
        ans += (i.x - last) * tot[1];
        //cout <<i.x-last<<' '<<tot[1]<<endl;
        update(1,1,idx,i.l,i.r,i.del);
        last = i.x;
    }
    cout << "Test case #"<<c<<endl;
    cout << "Total explored area: "<< fixed << setprecision(2)<<ans << endl;
}
}
