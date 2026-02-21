// Persistent Segment Tree (Chairman Tree)
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
int n, m, cnt, root[maxn],a[maxn], x, y, k;
struct node{
    int l,r,sum;
}T[maxn*40];
vector<int>v;
int getid(int x){
    return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}
void update(int l,int r,int &x,int y,int pos){
    T[++cnt] = T[y],T[cnt].sum++,x = cnt;
    if(l == r)return;
    int mid = (l + r) / 2;
    if(pos <= mid){
        update(l,mid,T[x].l,T[y].l,pos);
    }
    else{
        update(mid+1,r,T[x].r,T[y].r,pos);
    }
}
int query(int l,int r,int x,int y,int k){
    if(l==r)return l;
    int mid = (l + r) >> 1;
    int sum = T[T[y].l].sum - T[T[x].l].sum;
    if(sum >= k){
        return query(l,mid,T[x].l,T[y].l,k);
    }
    else{
        return query(mid+1,r,T[x].r,T[y].r,k-sum);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    f1(n)cin >> a[i], v.pb(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1 ; i <= n ; i++){
        update(1,n,root[i],root[i-1],getid(a[i]));
    }
    for(int i = 1 ; i <= m ; i++){
        cin >> x >> y >> k;
        cout << v[query(1,n,root[x-1],root[y],k)-1] << '\n';
    }
}
