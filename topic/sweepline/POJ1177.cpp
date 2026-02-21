#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 20005;
struct s{
    int x;
    int l,r,del;
};
bool cmp(s x,s y){
    return x.x < y.x;
}
int cnt[MAXN<<2];
int lbd[MAXN<<2];
int rbd[MAXN<<2];
int tr1[MAXN<<2];
int tr2[MAXN<<2];
void pushup(int x,int l,int r){
    if(cnt[x]){
        lbd[x] = rbd[x] = 1;
        tr1[x] = r - l + 1;
        tr2[x] = 2;
    }
    else{
        if(r - l){
            lbd[x] = lbd[x<<1];
            rbd[x] = rbd[x<<1|1];
            tr1[x] = tr1[x<<1] + tr1[x<<1|1];
            tr2[x] = tr2[x<<1] + tr2[x<<1|1];
            if(rbd[x<<1]&&lbd[x<<1|1]){
                tr2[x] -= 2;
            }
        }
        else{
            lbd[x] = rbd[x] = 0;
            tr1[x] = tr2[x] = 0;
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
    long long ans = 0;
    for (int i = 0; i < n; i++){
        int l, r, u, d;
        cin >> l >> u >> r >> d;
        l++;
        l += 10000,r += 10000; 
        v.push_back({u,l,r,1});
        v.push_back({d,l,r,-1});
    }
    sort(v.begin(),v.end(),cmp);
    int last = 0;
    int pre = 0;
    for(int i=0;i<2*n;i++){
        update(1,1,20000,v[i].l,v[i].r,v[i].del);
        ans += abs(tr1[1] - pre);
        //cout << tr1[1] - pre<<endl;
        pre = tr1[1];
        if(i<2*n-1){
            ans += tr2[1] * (v[i+1].x - v[i].x);
            //cout << tr2[1] * (v[i+1].x - v[i].x)<<endl;
        }
    }
    cout << ans << endl;
}
