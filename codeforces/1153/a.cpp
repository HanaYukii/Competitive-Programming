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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	while(cin >> n >> k){
		int mi=1e9,ans=0;
		f1(n){
			int add1,add2;
			cin >> add1 >> add2;
			while(add1<k){
				add1 += add2;
			}
			if(add1<mi){
				mi = add1;
				ans = i;
			}
		}
		cout << ans << endl;
	}

}