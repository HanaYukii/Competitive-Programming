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
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		set<int>t;
		vector<int>type;
		map<int,int>mp;
		type.clear();
		mp.clear();
		for(auto i:s){
			t.insert(i-'a');
			mp[i-'a']++;
		}
		for(auto i:t){
			type.pb(i);
		}
		//cout<<endl;
		if(type.size()==2&&type[0]+1==type[1]){
			cout<<"No answer"<<'\n';
			continue;
		}
		else if(type.size()==3&&type[0]+2==type[2]){
			cout<<"No answer"<<'\n';
			continue;
		}
		else if(type.size()==3&&type[0]+1==type[1]){
			for(int i=1;i<(int)type.size();i++){
				for(int j=0;j<mp[type[i]];j++){
					cout<<(char)('a'+type[i]);
				}
			}
			for(int j=0;j<mp[type[0]];j++){
					cout<<(char)('a'+type[0]);
			}
			cout<<'\n';
			continue;
		}
		for(int i=1;i<(int)type.size();i+=2){
			for(int j=0;j<mp[type[i]];j++){
				cout<<(char)('a'+type[i]);
			}
		}
		for(int i=0;i<(int)type.size();i+=2){
			for(int j=0;j<mp[type[i]];j++){
				cout<<(char)('a'+type[i]);
			}
		}
		
		cout<<'\n';
	}	
}