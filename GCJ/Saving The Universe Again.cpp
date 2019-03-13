#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[35],n;
int sum(){
	int ret=0;
	int now=1;
	f(n){
		if(!cont[i])now<<=1;
		else ret+=now;
	}
	return ret;
}
int main(){
	int t;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;c++){
		ms(cont);
		int k;
		string s;
		cin>>k>>s;
		n=s.length();
		int cnt=0;
		f(n){
			if(s[i]=='S'){
				cont[i]=1;
				cnt++;
			}
		}
		if(cnt>k){
			cout<<"Case #"<<c<<": "<<"IMPOSSIBLE"<<endl;
		}
		else{
			int ans=0;
			if(sum()<=k){
				cout<<"Case #"<<c<<": 0"<<endl;
			}
			else{
				while(1){
					ans++;
					for(int i=n-1;i>=1;i--){
						if(cont[i]==1&&cont[i-1]==0){
							swap(cont[i],cont[i-1]);
							break;
						}
					}
					if(sum()<=k){
						cout<<"Case #"<<c<<": "<<ans<<endl;
						break;
					}
				}
			}
		}
	}
}