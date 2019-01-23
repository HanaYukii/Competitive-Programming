#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
struct e{
	int l;
	int r;
	int idx;
	int f;
}cont[100005];
bool cmp(e x,e y){
	if(x.l!=y.l)
		return x.l<y.l;
	else
		return x.r<y.r;
}
bool cmp2(e x,e y){
	return x.idx<y.idx;
}
int main(void){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>cont[i].l>>cont[i].r;
			cont[i].idx=i;
		}
		sort(cont,cont+n,cmp);
		int now=0;
		int c=0;
		int t=0;
		while(now<n){
			t++;
			int nr=cont[now].r;
			cont[now].f=c;
			now++;
			while(cont[now].l<=nr&&now<n){
				cont[now].f=c;
				nr=max(nr,cont[now].r);
				now++;
			}
			c^=1;
		}
		sort(cont,cont+n,cmp2);
		if(t==1){
			cout<<-1<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				cout<<cont[i].f+1<<' ';
			}
			cout<<endl;
		}

	}
}