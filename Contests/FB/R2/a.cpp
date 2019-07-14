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
const ll mod = 1e9+7;

int main(){
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n,m,k,x,y;
		cin >> n >> m >> k;
		vector<pair<int,int> >v;
		cin >> x >> y;
		f(k){
			int add1,add2;
			cin >> add1 >> add2;
			v.pb({add1,add2});
		}
		if(k==1){
			printf("Case #%d: N\n",c);
		}
		else{
			int f = 0;
			for(auto i:v){
				if((i.first+i.second)%2!=(x+y)%2)f=1;
			}
			if(f){
				printf("Case #%d: N\n",c);
			}
			else{
				printf("Case #%d: Y\n",c);
			}
		}
	}

}