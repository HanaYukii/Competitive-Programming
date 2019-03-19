#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]
queue<int>l[27],r[27];
vector<pair<int,int> >ans;
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	while(cin>>n>>k){
		ll pre[k+5]={};
		f1(k){
			ll add;
			cin>>add;
			pre[i]=pre[i-1]+add;
		}
		ll mn=1e18;
		f1(k){
			mn=min(mn,pre[i]);
			if(pre[i]<=-n){
				cout<<i<<endl;
				exit(0);
			}
		}
		if(pre[k]>=0){
			cout<<-1<<endl;
			exit(0);
		}
		
		ll last=0;
		ll div=-n/pre[k];
		ll b=1;
		while(b<=div){
			b<<=1;
		}
		for(ll i=b;i;i>>=1){
			//cout<<pre[k]*(last+i)+mn<<endl;
			if(pre[k]*(last+i)+mn>-n){
				last+=i;
			}
		}
		ll now=pre[k]*last;
		//cout<<now<<endl;
		for(int i=1;i<=k;i++){
			if(now+pre[i]<=-n){
				cout<<last*k+i<<endl;
				exit(0);
			}
		}
		for(int i=1;i<=k;i++){
			if(now+pre[k]+pre[i]<=-n){
				cout<<last*k+k+i<<endl;
				exit(0);
			}
		}
		//cout<<"here"<<endl;
	}
		
		
}