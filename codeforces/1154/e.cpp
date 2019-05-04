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
int b[300073];
void update(int a,int k)
{
    while(a<=300000)
    {
        b[a]+=k;
        a+=(a&-a);
    }
}
int sum(int x){
	int ret=0;
	while(x){
		ret+=b[x];
		x-=(x&-x);
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	while(cin >>n>>m){
		int cont[n+5]={};
		map<int,int>p;
		int ans[n+5]={};
		set<int>rem;
		f1(n){
			rem.insert(i);
			update(i,1);
			cin>>cont[i];
			p[cont[i]]=i;
		}
		int left=n;
		int turn =0;
		while(left){
			int pos=sum(p[*(--rem.ed)]);
			int lb=max(1,pos-m),rb=min(left,pos+m);
			//cout<<lb<<' '<<rb<<endl;
			for(int i=lb;i<=rb;i++){
				int fi=0;
				for(int j=1<<17;j;j>>=1){
					if(sum(fi+j)<lb){
						fi+=j;
					}
				}
				//cout<<fi<<endl;
				ans[fi+1]=turn+1;
				rem.erase(cont[fi+1]);
				update(fi+1,-1);
				left--;
			}
			turn ^= 1;
		}
		f1(n){
			cout<<ans[i];
		}
		cout<<endl;
	}

}