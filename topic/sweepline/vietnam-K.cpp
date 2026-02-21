#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
struct s{
    long long x;
    long long L,R;
    int l,r,del;
};
bool cmp(s x,s y){
    return x.x < y.x;
}
int cnt[MAXN<<2];
long long tot[MAXN<<2];
long long tote[MAXN<<2];
long long toto[MAXN<<2];
map<long long,int>mp;
long long pre[MAXN];
int idx;
void init(){
    idx = 0;
    memset(pre,0,sizeof(pre));
    memset(tot,0,sizeof(tot));
    mp.clear();
    memset(cnt,0,sizeof(cnt));
    memset(toto,0,sizeof(toto));
    memset(tote,0,sizeof(tote));
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
    if(cnt[x]&1){
        if(r-l==0){
            toto[x] = pre[r] - pre[l-1];
            tote[x] = 0;
        }
        else{
            tote[x] = toto[x<<1] + toto[x<<1|1];
            toto[x] = tote[x<<1] + tote[x<<1|1];
        }
    }
    else{
        if(r-l==0){
            toto[x] = 0;
            tote[x] = pre[r] - pre[l-1];
        }
        else{
            tote[x] = tote[x<<1] + tote[x<<1|1];
            toto[x] = toto[x<<1] + toto[x<<1|1];
        }
    }
}
void build(int x,int l,int r){
    if(l==r){
        pushup(x,l,r);
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x,l,r);
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
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    int t;
    //cin >> t;
    //while(t--){
    cin >> n;
    init();
    vector<s>v;
    for (int i = 0; i < n; i++){
        long long l, r, u, d;
        cin >> l >> u >> r >> d;
        if(l>r){
            swap(l,r);
        }
        if(u>d){
            swap(u,d);
        }
        v.push_back({u,l,r,0,0,1});
        v.push_back({d,l,r,0,0,-1});
        mp[l];
        mp[r];
    }   
    for(auto &i:mp){
        i.second = ++idx;
        pre[idx] = i.first;
    }
    for(auto &i:v){
        i.l = mp[i.L] + 1;
        i.r = mp[i.R];
    }
    sort(v.begin(),v.end(),cmp);
    long long last = 0;
    long long ans = 0;
    build(1,1,idx);
    for(auto i:v){
        ans += (i.x - last) * (tot[1] - toto[1]);
        //cout <<i.x-last<<' '<<tot[1]<<endl;
        update(1,1,idx,i.l,i.r,i.del);
        last = i.x;
    }
    cout << ans << endl;
    //}
}
