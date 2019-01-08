#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>cont[i];
		}
		vector<int>ans;
		for(int i=1;i<=n;i++){
			int f=0;
			for(int j=0;j<=n-1-i;j++){
				if(cont[j+1]-cont[j]!=cont[j+1+i]-cont[j+i]){
					f=1;
				}
			}
			if(!f){
				ans.pb(i);
			}
		}
		cout<<ans.size()<<endl;
		for(auto i:ans){
			cout<<i<<' ';
		}		
		cout<<endl;
	}
}	
