#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
struct node
{
	ll gcd;
}tree[maxn<<2];
void pushup(int now){
	tree[now].gcd=__gcd(tree[now<<1].gcd,tree[now<<1|1].gcd);
}
void build(int now,int l,int r){
	if(l==r){
		tree[now].gcd=cont[l];
		return;
	}
	int mid=(l+r)/2;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	pushup(now);
}
void update(int now,int l,int r,int L,int R){
	if(l==r){
		tree[now].gcd=cont[l];
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid){
		update(now<<1,l,mid,L,R);
	}
	if(R>mid){
		update(now<<1|1,mid+1,r,L,R);
	}
	pushup(now);
}
ll query(int now,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return tree[now].gcd;
	}
	int mid=(l+r)>>1;
	ll ret=0;
	if(L<=mid){
		ret=__gcd(ret,query(now<<1,l,mid,L,R));
	}
	if(mid<R){
		ret=__gcd(ret,query(now<<1|1,mid+1,r,L,R));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		f1(n){
			cont[i] = 1;
		}
		build(1,1,n);
		f(m){
			int tp,pos,add;
			cin >> tp >> pos >> add;
			if(tp == 1){
				cont[pos] = add;
				update(1,1,n,pos,pos);
			}
			else{
				if(query(1,1,n,pos,n)>add){
					cout<<"DOYA!"<<endl;
				}
				else{
					ll ans=0;
					for(ll j=1LL<<19;j;j>>=1){
						ll now=(1LL<<20)-j-ans;
						if(pos+now>n){
							ans += j;
							continue;
						}
						if(query(1,1,n,pos,pos+now)<=add){
							cout<<now<<' '<<query(1,1,n,pos,pos+now)<<endl;
							ans += j;
						}
					}
					ans = (1LL<<20)-ans;
					cout<<ans<<'\n';
				}
			}
		}
		
	}
	
}