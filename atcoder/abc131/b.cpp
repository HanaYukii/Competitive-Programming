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
#define F first
#define S second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,l;
	while(cin >> n >> l){
		int r = l+n-1;
		int mi = 1e9;
		int sum = 0;
		for(int i = l ; i <= r ; i++){
			if(abs(i)<abs(mi)){
				mi = i;
			}
			sum += i;
		}
		cout << sum - mi << endl;
	}
}