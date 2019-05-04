#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
int cont[200005],last[200005];
int pos[200005];
int dp[200005][20];
int start[200005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,q;
	while(cin >> n){
		int mi=0,z=0,po=0;
		f(n){
			int add;
			cin >> add;
			if(add==0)z++;
			else if(add > 0)po++;
			else mi++;
		}
		if(mi>=(n/2)+(n&1)){
			cout<<-1<<endl;
		}
		else if(po>=(n/2)+(n&1)){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
}