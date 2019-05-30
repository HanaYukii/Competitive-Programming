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
#define pii pair<int,int>

int main(){
	int n,m,h;
	while(cin >> n >> h >> m){
		int cont[n+5] ={};
		f1(n){
			cont[i]=h;
		}
		f(m){
			int l,r,c;
			cin >> l >> r >> c;
			fr(j,l,r+1){
				cont[j]=min(cont[j],c);
			}
		}
		int sum = 0;
		f1(n){
			sum += cont[i]*cont[i];
		}
		cout << sum <<endl;
	}
}