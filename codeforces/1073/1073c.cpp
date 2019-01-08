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
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	string s;
	int n;
	while(cin>>n){
		string s;
		cin>>s;
		int px=0,py=0;
		int f=0;
		int x,y;
		cin>>x>>y;
		if(abs(x)+abs(y)>n){
			f=1;
		}
		else if((abs(x)+abs(y)-n)&1){
			f=1;
		}
		if(f){
			cout<<-1<<endl;
			continue;
		}
		int lpx[maxn]={},lpy[maxn]={},rpx[maxn]={},rpy[maxn]={};
		for(int i=0;i<n;i++){
			if(s[i]=='R'){
				px++;
			}
			else if(s[i]=='U'){
				py++;
			}
			else if(s[i]=='L'){
				px--;
			}
			else{
				py--;
			}
			lpx[i+1]=px;
			lpy[i+1]=py;
		}
		px=x,py=y;
		rpx[n]=px,rpy[n]=py;
		for(int i=n-1;i>=0;i--){
			if(s[i]=='R'){
				px--;
			}
			else if(s[i]=='U'){
				py--;
			}
			else if(s[i]=='L'){
				px++;
			}
			else{
				py++;
			}
			rpx[i]=px;
			rpy[i]=py;
		}
		int r=n;
		int ans=n;
		for(int i=0;i<=n;i++){
			if(abs(lpx[i]-rpx[r])+abs(lpy[i]-rpy[r])<=r-i){
				while(abs(lpx[i]-rpx[r])+abs(lpy[i]-rpy[r])<=r-i){
					ans=min(ans,r-i);
					if(r==i)
						break;
					else
						r--;
				}
				r++;
				r=min(r,n);
				if(ans==0)
					break;
			}
			else{
				while(!(abs(lpx[i]-rpx[r])+abs(lpy[i]-rpy[r])<r-i)&&r<=n){
					r++;
				}
				r=min(r,n);
				if(abs(lpx[i]-rpx[r])+abs(lpy[i]-rpy[r])<=r-i)
					ans=min(ans,r-i);
			}
		}
		cout<<ans<<endl;
	}	
}