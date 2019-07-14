#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 250005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
bool cmp(pair<int,int>x, pair<int,int>y){
	return x.second > y.second;
}
struct seg
{
	int v;	
}tree[maxn<<2];
void pushup(int idx){
	tree[idx].v = tree[idx<<1].v + tree[idx<<1|1].v;
}
void build(int idx,int l,int r){
	if(l==r){
		tree[idx].v = 0;
		return ;
	}
	int mid = (l+r) >> 1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	pushup(idx);
}
void update(int idx,int l,int r,int x){
	if(l==r){
		tree[idx].v = 1;
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
int query(int idx,int l,int r,int ql,int qr){
	if(ql <= l && qr >= r){
		return tree[idx].v;
	}
	int ret = 0;
	int mid = (l+r) >> 1;
	if(ql <= mid){
		ret += query(idx<<1,l,mid,ql,qr);
	}
	if(qr > mid){
		ret += query(idx<<1|1,mid+1,r,ql,qr);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	while(cin >> n){
		vector<pair<int,int> >p;
		vector<int>dis;
		unordered_map<int,int>mp;
		f(n){
			int add1,add2;
			cin >> add1 >> add2;
			dis.pb(add1);
			p.pb({add1,add2});
		}
		sort(dis.begin(),dis.end());
		for(int i=1;i<=(int)dis.size();i++){
			mp[dis[i-1]] = i;
		}
		for(auto &i:p){
			i.first = mp[i.first];
		}
		sort(p.begin(),p.end(),cmp);
		int pre = p[0].second;
		vector<int>now;
		ll ans = 0;
		//cout<<"gg"<<endl;
		build(1,1,n);
		for(int i = 0 ; i < n ;i++){
			if(p[i].second == pre){
				now.pb(p[i].first);
			}
			else{
				ll nok = 0;
				ll ok = 0;
				now.pb(0);
				now.pb(n+1);
				sort(now.begin(),now.end());
				for(int j=1;j<(int)now.size();j++){
					if(now[j]-1 == now[j-1])continue;
					int ql = now[j-1]+1,qr = now[j]-1;
					if(ql>qr)continue;
					ll cnt = query(1,1,n,ql,qr);
					nok += cnt * (cnt+1)/2;
				}
				for(int j = 1 ; j < (int)now.size()-1;j++){
						update(1,1,n,now[j]);
				}
				ok = query(1,1,n,1,n);
				ok = ok*(ok+1)/2;
				ans += ok - nok;
				//cout<<ok<<' '<<nok<<endl;
				
				pre = p[i].second;
				now.clear();
				now.pb(p[i].first);
				
			}
		}
		ll nok = 0;
		ll ok = 0;
		now.pb(0);
		now.pb(n+1);
		sort(now.begin(),now.end());
		for(int j=1;j<(int)now.size();j++){
			if(now[j]-1 == now[j-1])continue;
			int ql = now[j-1]+1,qr = now[j]-1;
			if(ql>qr)continue;
			ll cnt = query(1,1,n,ql,qr);
			nok += cnt * (cnt+1)/2;
		}
		for(int j = 1 ; j < (int)now.size()-1;j++){
			update(1,1,n,now[j]);
		}
		ok = query(1,1,n,1,n);
		ok = ok*(ok+1)/2;
		ans += ok - nok;
		//cout<<ok<<' '<<nok<<endl;
		cout << ans << endl;
	}
}