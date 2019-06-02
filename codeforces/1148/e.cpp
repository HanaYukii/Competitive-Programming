#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
int b[300005];
void update(int x,int d){
	while(x<=300000){
		b[x]+=d;
		x += x&(-x);
	}
}
int sum(int x){
	int ret = 0;
	while(x){
		ret += b[x];
		x -= x&(-x);
	}
	return ret;
}
struct s
{
	int p1,p2;
	ll d;
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;//,m,k,ta,tb;
	while(cin >> n ){
		vector<s>ans;
		vector<pair<ll,int> >v1;
		vector<ll> v2;
		//ll sum = 0;
		f(n){
			ll add;
			cin >> add;
			v1.pb({add,i+1});
			//sum += add;
		}
		f(n){
			ll add;
			cin >> add;
			v2.pb(add);
			//sum -= add;
		}

		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());

		int idx[n+5] = {};
		ll del[n+5]={};
		f(n){
			idx[i] = v1[i].second;
		}
		f(n){
			del[i] = v2[i] - v1[i].first;
		}
		stack<int>st;
		for(int i=0;i<n;i++){
			if(del[i]>0){
				st.push(i);
				continue;
			}
			if(del[i]==0)continue;
			while(del[i]){
				if(st.empty()){
					cout << "NO" << endl;
					exit(0);
				}
				int tp = st.top();
				ll d=min(del[tp],-del[i]);
				del[tp] -= d;
				del[i] += d;
				s add;
				add.p1 = idx[tp];
				add.p2 = idx[i];
				add.d = d;
				ans.pb(add);
				if(!del[tp])st.pop(); 
			}
		}
		if(st.size()){
			cout<<"NO"<<endl;
			exit(0);
		}
		cout <<"YES"<<endl;
		cout << ans.size()<<endl;
		for(auto i:ans){
			cout <<i.p1<<' '<<i.p2<<' '<<i.d<<endl;
		}
	}
	
}