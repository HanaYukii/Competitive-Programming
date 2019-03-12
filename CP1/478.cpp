#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn=1005;

int bit[100005];
int n;
void add(int x){
	while(x<=100000){
		bit[x]++;
		x+=(x&-x);
	}
}
int sum(int x){
	int sum=0;
	while(x){
		sum+=bit[x];
		x-=(x&(-x));
	}
	return sum;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		ms(bit);
		int n;
		cin>>n;
		ll cont[n+5]={};
		int rk[n+5]={};
		f(n)cin>>cont[i];
		f(n){
			add(cont[i]);
			rk[i]=sum(100000)-sum(cont[i]);
		}
		ll ans=0;
		int f=0,last;
		//f(n)cout<<rk[i]<<' ';
		//cout<<endl;
		for(int i=n-1;i>=0;i--){
			if(!f){
				if(rk[i]!=0){
					f=1;
					for(int j=i-1;j>=0;j--){
						if(cont[j]>cont[i]){
							ans+=(cont[j]-cont[i])*cont[i];
						}
					}
					last=cont[i];
				}
			}
			else{
				if(cont[i]<last){
					ans+=rk[i]*(last-cont[i])*cont[i];
					last=cont[i];
				}
			}
			cout<<ans<<endl;
		}
		
	}

}