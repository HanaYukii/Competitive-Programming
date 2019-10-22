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
struct seg{
    int l,r,idx;
};
int lz[maxn<<2];
int mx[maxn<<2];
bool cmp(seg x,seg y){
    if(x.r==y.r){
        return x.l>y.l;
    }
    else{
        return x.r<y.r;
    }
}
void pushdown(int x){
    if(!lz[x])return;
    lz[x<<1] += lz[x];
    lz[x<<1|1] += lz[x];
    mx[x<<1] += lz[x];
    mx[x<<1|1] += lz[x];
    lz[x] = 0;
}
void pushup(int x){
    mx[x] = max(mx[x<<1],mx[x<<1|1]);
}
void update(int x,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr){
        mx[x]++;
        lz[x]++;
        return;
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
    if(l >= ql && r <= qr){
        return mx[x];
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    int ret = 0;
    if(ql <= mid){
        ret = max(ret,query(x<<1,l,mid,ql,qr));
    }
    if(qr > mid){
        ret = max(ret,query(x<<1|1,mid+1,r,ql,qr));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    vector<seg>v;
    f(n){
        int l, r;
        cin >> l >> r;
        v.pb({l,r,i+1});
    }
    sort(v.begin(),v.end(),cmp);
    vector<int>ans;
    for(auto i:v){
        int mxx = query(1,1,200000,i.l,i.r);
        if(mxx == k){
            ans.pb(i.idx);
        }
        else{
            update(1,1,200000,i.l,i.r);
        }
    }
    sort(ans.begin(),ans.end()); 
    cout << ans.size() << endl;
    for(auto i:ans){
        cout<<i<<' ';
    }
    cout << endl;
}
