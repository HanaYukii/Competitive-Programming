#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const int maxn=200005;
struct e{
	int f,s;
}cont[maxn];
int deg[maxn];
int d[maxn];
int fi(int x){
	return d[x]==x?x:d[x]=fi(d[x]);
}
int main(void){
	ios_base::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		f(m){
			cin>>cont[i].f>>cont[i].s;
			deg[cont[i].f]++,deg[cont[i].s]++;
		}
		int st=0,mx=0;
		f1(n){
			if(deg[i]>mx){
				mx=deg[i];
				st=i;
			}
		}
		f1(n)d[i]=i;
		f(m){
			if(cont[i].f==st||cont[i].s==st){
				cout<<cont[i].f<<' '<<cont[i].s<<'\n';
				d[fi(cont[i].f)]=fi(cont[i].s);
			}
		}
		f(m){
			int x=fi(cont[i].f),y=fi(cont[i].s);
			if(x!=y){
				cout<<cont[i].f<<' '<<cont[i].s<<'\n';
				d[x]=y;
			}
		}
	}
}