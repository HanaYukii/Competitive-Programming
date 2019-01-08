#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;

int main(){
	int n,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n){
		unordered_map<string,int>mp;
		unordered_map<string,int>mp2;
		string cont[10005];
		fr(k,1,n+1){
			string s;
			cin>>s;
			cont[k]=s;
			unordered_map<string,int>mp3;
			f((int)s.length()){
				fr(j,i,(int)s.length()){
					mp3[s.substr(i,j-i+1)]=k;
				}
			}
			for(auto i:mp3){
				mp[i.first]++;
				mp2[i.first]=k;
			}
		}
		cin>>m;
		f(m){
			string s;
			cin>>s;
			if(mp.find(s)==mp.end()){
				cout<<0<<' '<<'-'<<endl;
			}
			else{
				cout<<mp[s]<<' '<<cont[mp2[s]]<<endl;
			}
		}
	}	
}