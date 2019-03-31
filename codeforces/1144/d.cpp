#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		map<ll,int>mp;
		int mx=0;
		ll num=0;
		f1(n){
			cin>>cont[i];
			mp[cont[i]]++;
			if(mp[cont[i]]>mx){
				mx=mp[cont[i]];
				num=cont[i];
			}
		}
		cout<<n-mx<<endl;
		vector<int>pos;
		pos.pb(0);
		f1(n){
			if(cont[i]==num){
				pos.pb(i);
			}
		}
		for(int i=1;i<(int)pos.size();i++){
			for(int j=pos[i];j>pos[i-1]+1;j--){
				if(cont[j-1]<num)
					cout<<1<<' '<<j-1<<' '<<j<<endl;
				else
					cout<<2<<' '<<j-1<<' '<<j<<endl;
			}
		}
		for(int i=*(--pos.end());i<=n-1;i++){
			if(cont[i+1]<num)
				cout<<1<<' '<<i+1<<' '<<i<<endl;
			else
				cout<<2<<' '<<i+1<<' '<<i<<endl;
		}
	}


}