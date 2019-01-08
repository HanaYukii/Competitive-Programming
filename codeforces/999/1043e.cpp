#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
struct s{
	ll f,s,idx;
}cont[maxn];
bool cmp(s x,s y){
	return x.f-x.s<y.f-y.s;
}
ll pre[maxn],suf[maxn];
int pos[maxn];
ll ans[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin>>n>>m){
			f1(n){
				cin>>cont[i].f>>cont[i].s;
				cont[i].idx=i;
			}
			sort(cont+1,cont+1+n,cmp);
			f1(n){
				pos[cont[i].idx]=i;
			}
			f1(n){
				pre[i]=pre[i-1]+cont[i].f;
			}
			for(int i=n;i>=1;i--){
				suf[i]=suf[i+1]+cont[i].s;
			}
			for(int i=1;i<=n;i++){
				ans[cont[i].idx]=pre[i-1]+cont[i].s*(i-1)+suf[i+1]+cont[i].f*(n-i);
			}
			f(m){
				int add1,add2;
				cin>>add1>>add2;
				int p1=pos[add1],p2=pos[add2];
				ans[add1]-=min(cont[p1].f+cont[p2].s,cont[p2].f+cont[p1].s);
				ans[add2]-=min(cont[p1].f+cont[p2].s,cont[p2].f+cont[p1].s);
			}
			f1(n){
				cout<<ans[i]<<' ';
			}
			cout<<endl;
		}
}

