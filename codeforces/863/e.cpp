#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

struct s
{
	int l,r;
	int idx;
}cont[274751];
bool cmp(s x,s y){
	if(x.l==y.l)
		return x.r<y.r;
	else
		return x.l<y.l;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	while(cin >> n ){
		f(n){
			cin >> cont[i].l >> cont[i].r;
			cont[i].idx=i+1;
		}
		sort(cont,cont+n,cmp);
		int r=cont[0].r;
		f1(n-1){
			if(cont[i-1].l==cont[i].l){
				cout<<cont[i-1].idx<<endl;
				exit(0);
			}
			if(cont[i].r<=r){

				cout<<cont[i].idx<<endl;
				exit(0);
			}
			else if(cont[i+1].l<=r+1&&cont[i+1].r>=cont[i].r){
				cout<<cont[i].idx<<endl;
				exit(0);
			}
			else{
				r=max(r,cont[i].r);
			}
		}
		cout<<-1<<endl;
	}
	
}