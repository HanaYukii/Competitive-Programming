#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		map<int,int>mp;
		f(n){
			int add;
			cin>>add;
			mp[add]++;
		}
		for(auto i:mp){
			if(i.second>2){
				cout<<"NO"<<endl;
				exit(0);
			}
		}
		cout<<"YES"<<endl;
		cout<<mp.size()<<endl;
		set<int>era;
		for(auto i:mp){
			cout<<i.first<<' ';
			if(i.second==1){
				era.insert(i.first);
			}
		}
		cout<<endl;
		for(auto i:era)mp.erase(i);
		cout<<mp.size()<<endl;
		vector<int>out;
		for(auto i:mp){
			out.pb(i.first);
		}
		reverse(out.begin(),out.end());
		for(auto i:out){
			cout<<i<<' ';
		}
		cout<<endl;
	}

}