#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
struct s{
	ll num,idx;
}cont[maxn];
bool cmp(s x,s y){
	return x.num>y.num;
}
int main(){
	ll n;
	while(cin>>n){
		int Min=0;
		for(int i=(1<<29);i;i>>=1){
			if(Min+i<=1e9){
				cout<<'>'<<' '<<Min+i<<endl;
				int ret;
				cin>>ret;
				if(ret==1){
					Min+=i;
				}
			}
		}
		int Max=Min+1;
		srand(time(NULL));
		vector<int>num;
		f(30){
			int ask=((rand()*rand())|rand())%n;
			ask++;
			cout<<'?'<<' '<<ask<<endl;
			int ret;
			cin>>ret;
			num.pb(ret);
		}
		sort(num.begin(),num.end());
		int gcd=num[1]-num[0];
		f1(28){
			gcd=__gcd(gcd,num[i+1]-num[i]);
		}
		cout<<'!'<<' '<<Max-(n-1)*gcd<<' '<<gcd<<endl;
	}
}