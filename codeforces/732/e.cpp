#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		int ans[200005] = {};
		int now[200005];
		int cont[200005];
		int u[200005] ;
		ms(u);
		multiset<int>st;
		map<int,set<int>>mp;
		f1(n){
			cin >> cont[i];
			st.insert(cont[i]);
			mp[cont[i]].insert(i);
		}
		f1(m){
			cin >> now[i];
		}
		int sum =0,cnt = 0;
		f(32){
			fr(j,1,m+1){
				if(u[j]!=-1)continue;
				if(st.find(now[j])!=st.end()){
					st.erase(st.lower_bound(now[j]));
					int use=*mp[now[j]].begin();
					mp[now[j]].erase(use);
					ans[use] = j;
					u[j] = i;
					sum += i;
					cnt++;
				}
			}
			fr(j,1,m+1){
				if(now[j]&1)
					now[j]=now[j]/2+1;
				else
					now[j]=now[j]/2;
			}
		}
		cout <<cnt<<' '<<sum<<endl;
		f1(m){
			cout<<max(u[i],0)<<' ';
		}
		cout<<endl;
		f1(n){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
	
}