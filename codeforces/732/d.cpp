#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;
	while(cin >> n >> m){
		vector<int>v[100005];
		int need[100005] = {};
		f1(n){
			int add;
			cin >> add;
			if(add)v[add].pb(i);
		}
		f1(m){
			cin >> need[i];
		}
		vector<pair<int,int> >t;
		f1(m){
			if(v[i].empty()){
				cout<<-1<<endl;
				exit(0);
			}
			t.pb({v[i][v[i].size()-1],need[i]});
		}
		sort(t.begin(),t.end());
		int s=0,last=1,tot=0;
		for(auto i:t){
			tot += i.second;
			s += i.first-last;
			if(s<tot){
				cout<<-1<<endl;
				exit(0);
			}
			last = i.first + 1;
		}
		int ans = 0;
		for(int i = 1<<18;i;i>>=1){
			t.clear();
			int now=n-ans-i;
			int f=0;
			if(now<=0)continue;
			//cout<<now<<endl;
			fr(j,1,m+1){
				if(upper_bound(v[j].begin(),v[j].end(),now)==v[j].begin()){
					f=1;
					break;
				}
				//cout<<*(--upper_bound(v[j].begin(),v[j].end(),now))<<' '<<j<<endl;
				t.pb({*(--upper_bound(v[j].begin(),v[j].end(),now)),need[j]});
			}
			int s=0,last=1,tot=0;
			sort(t.begin(),t.end());
			for(auto j:t){
				tot += j.second;
				s += j.first-last;
				//cout<<s<<' '<<tot<<endl;
				if(s<tot){
					f=1;
					break;
				}
				last = j.first + 1;
			}
			if(!f){
				ans += i;
			}
		}
		cout << n-ans << endl;
	}
	
}