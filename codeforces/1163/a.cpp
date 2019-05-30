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

int main(){
	int n,m;
	while(cin >> n >> m){
		if(m==0){
			cout<<1<<endl;
		}
		else if(n==m){
			cout<<0<<endl;
		}
		else{
			int mx=n/2;
			if(m<=mx){
				cout<<m<<endl;
			}
			else{
				cout<<n-m<<endl;
			}
		}
	}
}