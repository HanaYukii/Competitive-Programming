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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll a,b,c;
	while(cin >> a>>b>>c){
		int day[7]={1,2,3,1,3,2,1};
		int ans=0;
		for(int i=1<<30;i;i>>=1){
			ll aa=3*((ans+i)/7),bb=2*((ans+i)/7),cc=2*((ans+i)/7);
			int f=0;
			for(int j=0;j<7;j++){
				int le=(ans+i)%7;
				int now=j;
				ll ta=0,tb=0,tc=0;
				while(le--){
					if(day[now]==1)ta++;
					else if(day[now]==2)tb++;
					else tc++;
					now++;
					now%=7;
				}
				if(aa+ta<=a&&bb+tb<=b&&cc+tc<=c)f=1;	
			}
			if(f){
				ans+=i;
			}
		}
		cout << ans << endl;
	}

}