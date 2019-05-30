#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int N=1048576;
int num[1050005];
int b[1050005];
void add(int x,int d){
	//cout<<N<<endl;
	while(x<=N){
		//cout<<x<<endl;
		//cout<<x<<' '<<d<<endl;
		b[x] += d;
		x += (x&(-x));
	}
}
int sum(int x){
	int s = 0;
	while(x){
		//cout<<x<<endl;
		s += b[x];
		//cout<<b[x]<<endl;
		x -= (x&(-x));
	}
	return s;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n ,m;
		cin >> n >> m;
		ms(num);
		ms(b);
		f1(n){
			num[i]=1;
			add(i,1);
		}
		f(m){
			int tp,x;
			cin >> tp >> x;
			if(tp==1){
				num[x]++;
				add(x,1);
			}
			else if(tp==2){
				add(x,1-num[x]);
				num[x]=1;
			}
			else{
				//cout << sum(n)<<endl;
				if(sum(n)<x){
					cout<<"endro~!"<<'\n';
				}
				else{
					ll ans=0;
					for(ll j=1LL<<19;j;j>>=1){
						ll now=(1LL<<20)-j-ans;
						if(sum(now)>=x){
							ans += j;
						}
					}
					ans = (1LL<<20)-ans;
					num[ans]--;
					add(ans,-1);
					cout<<ans<<'\n';
				}
			}
		}
	}
	
}