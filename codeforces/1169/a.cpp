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
	int n,a,b,x,y;
	while(cin >> n >> a >> b >> x >> y){
		int t=min(b,y);
		int nx=a,ny=x;
		if(nx==ny){
			cout<<"YES"<<endl;
			exit(0);
		}
		while(1){
			nx++;
			if(nx==n+1)nx=1;
			ny--;
			if(ny==0)ny=n;
			if(nx==ny){
				cout<<"YES"<<endl;
				exit(0);
			}
			if(nx==b||ny==y){
				break;
			}
		}
		cout<<"NO"<<endl;
	}
}