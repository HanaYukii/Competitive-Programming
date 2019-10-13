#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
//#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
ll mat[1005][1005];
ll ans[1005];
map<ll,int>mp;
void br(ll x){
	for(int i=2;i<=sqrt(x);i++){
		while(x%i==0){
			x /= i;
			mp[i]++;
		}
	}
	mp[x]++;
}
void build(int id1,int id2,int id3){
	mp.clear();
	br(mat[id1][id2]);
	br(mat[id2][id3]);
	br(mat[id3][id1]);
	ll sq = 1;
	for(auto i:mp){
		ll base = i.F;
		int num = i.S >> 1;
		fr(j,0,num){
			sq *= base;
		}
	}
	ans[id1] = sq / mat[id2][id3];
	ans[id2] = sq / mat[id1][id3];
	ans[id3] = sq / mat[id1][id2];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	f(n){
		fr(j,0,n){
			cin >> mat[i][j];
		}
	}
	for(int i=0;i<n;i+=3){
		int id1 = i;
		int id2 = (i+1)%n;
		int id3 = (i+2)%n;
		build(id1,id2,id3);
	}
	f(n){
		cout<<ans[i]<<' ';
	}
	cout << endl;
}