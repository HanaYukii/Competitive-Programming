#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
int mi[maxn<<2];
int pos[maxn<<2];
void pushup(int x){
    if(mi[x<<1] <= mi[x<<1|1]){
        mi[x] = mi[x<<1];
        pos[x] = pos[x<<1];
    }
    else{
        mi[x] = mi[x<<1|1];
        pos[x] = pos[x<<1|1];
    }
}
void build(int x,int l,int r){
    if(l==r){
        mi[x] = 0;
        pos[x] = l;
        return ;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int idx,int l,int r,int x){
    if(l==r){
        mi[idx]++;
        return ;
    }
    int mid = (l+r) >> 1;
    if(x <= mid){
        update(idx<<1,l,mid,x);
    }
    else{
        update(idx<<1|1,mid+1,r,x);
    }
    pushup(idx);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    build(1,0,k-1);
    f(n){
        int add;
        cin >> add;
        update(1,0,k-1,add%k);
        //cout << mi[1] <<' '<<pos[1]<<endl; 
        cout << mi[1] * k + pos[1] << '\n';
    }
}
