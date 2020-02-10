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

ll sum[maxn<<2];
void pushup(int x){
	sum[x] = sum[x<<1] + sum[x<<1|1];
}
void build(int x,int l,int r){
	if(l==r){
		cin >> sum[x];
		return ;
	}
	int mid = (l+r) >> 1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
void update(int x,int l,int r,int p,int del){
	if(l==r){
		sum[x] += del;
		return ;
	}
	int mid = (l+r) >> 1;
	if(p <= mid){
		update(x<<1,l,mid,p,del);
	}
	else{
		update(x<<1|1,mid+1,r,p,del);
	}
	pushup(x);
}
ll query(int x,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r){
		return sum[x];
	}
	ll ret = 0;
	int mid = (l+r) >> 1;
	if(ql <= mid){
		ret += query(x<<1,l,mid,ql,qr);
	}
	if(qr > mid){
		ret += query(x<<1|1,mid+1,r,ql,qr);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);				
}
