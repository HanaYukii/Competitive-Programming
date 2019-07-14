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
const ll mod = 1e9+7;

int main(){
	int n;
	while(cin >> n){
		int deg[n+5] = {};
		f(n-1){
			int add1,add2;
			cin >> add1 >> add2;
			deg[add1]++,deg[add2]++;
		}
		int f = 0;
		f1(n){
			if(deg[i]==2){
				f = 1;
			}
		}
		if(f){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
}