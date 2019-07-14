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
#define bg begin()
#define ed end()
#define pii pair<int,int>
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		map<char,int>v;
		int u[n+5] = {};
		v['a']=1;
		v['e']=2;
		v['i']=3;
		v['o']=4;
		v['u']=5;
		vector<string>w;
		f(n){
			string s;
			cin >> s;
			w.pb(s);
		}
		map<pair<int,int>,int >mp;
		map<int,set<int> >cv;
		map<int,set<int> >sv;
		vector<pair<int,int> >fp;
		vector<pair<int,int> >scv;
		vector<pair<int,int> >ssv;
		f1(n){
			int last = 0;
			int cnt = 0;
			for(auto j:w[i-1]){
				if(v.find(j)==v.end())continue;
				cnt++;
				last=v[j];
			}
			if(mp[{cnt,last}]!=0){
				int op=mp[{cnt,last}];
				mp[{cnt,last}] = 0;
				fp.pb({op,i});
				u[op] = 1;
				u[i] = 1;
			}
			else{
				mp[{cnt,last}]=i;
			}
			cv[cnt].insert(i);
			sv[last].insert(i);
		}
		for(auto i:cv){
			vector<int>add;
			add.clear();
			for(auto j:i.second){
				if(!u[j]){
					add.pb(j);
				}
				if(add.size()==2){
					scv.pb({add[0],add[1]});
					u[add[0]]=1;
					u[add[1]]=1;
					add.clear();
				}
			}
		}
		for(auto i:sv){
			vector<int>add;
			add.clear();
			for(auto j:i.second){
				if(!u[j]){
					add.pb(j);
				}
				if(add.size()==2){
					ssv.pb({add[0],add[1]});
					u[add[0]]=1;
					u[add[1]]=1;
					add.clear();
				}
			}
		}
		/*for(auto i:fp){
			cout<<w[i.first]<<' '<<w[i.second]
		}*/
		vector<vector<pair<int,int> > >ans;
		while(fp.size()&&scv.size()){
			vector<pair<int,int> >add;
			add.pb(scv.back());
			scv.pop_back();
			add.pb(fp.back());
			fp.pop_back();
			ans.pb(add);
		}
		while(fp.size()>=2){
			vector<pair<int,int> >add;
			add.pb(fp.back());
			fp.pop_back();
			add.pb(fp.back());
			fp.pop_back();
			ans.pb(add);
		}
		
		cout<<ans.size()<<endl;
		for(auto i:ans){
			vector<int>v1,v2;
			for(auto j:i){
				v1.pb(j.first);
				v2.pb(j.second);
			}
			for(auto j:v1){
				cout<<w[j-1]<<' ';
			}
			cout<<endl;
			for(auto j:v2){
				cout<<w[j-1]<<' ';
			}
			cout<<endl;
		}
	}
}