#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q;
	while(cin >> n >> q){
		for(int i=1;i;i++){
			int now=n*i;
			if(now%10==0||now%10==q){
				cout<<i<<endl;
				exit(0);
			}
		}
	}
	
}