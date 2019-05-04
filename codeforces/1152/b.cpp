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
bool test(int x){
	int ret=0;
	while(x){
		if(!(x&1)){
			ret = 1;
			break;
		}
		x >>= 1;
	}
	return ret^1;
}
int tb(int x){
	int ret=0;
	while(x){
		ret++;
		x >>= 1;
		//cout<<ret<<'z'<<endl;
	}
	return ret;
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	//int now=0;
	while(cin >>n){
		vector<int>fl;
		ll now=n,cnt=0;
		while(1){
			//cout<<now<<endl;
			//system("PAUSE");
			if(test(now)){
				cout<<cnt<<endl;
				for(auto i:fl){
					cout<<i<<' ';
				}
				cout<<endl;
				break;
			}
			if(cnt&1){
				now++;
				cnt++;
				continue;
			}
			int k=tb(now);
			//cout<<k<<endl;
			//k = rand()%k+1;
			//cout<<k<<endl;
			now ^= (1<<k)-1;
			fl.pb(k);
			
			cnt++;
		}
	}

}