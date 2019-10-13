#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int u[n*3+5] = {};
		int um[k+5] = {};
		int cur=0;
		f1(k){
			int add1,add2;
			cin >> add1 >> add2;
			if(!u[add1]&&!u[add2]){
				u[add1]=u[add2]=1;
				um[i] = 1;
				cur += 2;
			}
		}
		if(cur >= n*2){
			cout<<"Matching"<<'\n';
			int now = 0;
			f1(k){
				if(um[i]){
					cout<<i<<' ';
					now++;
				}
				if(now == n)break;
			}
			cout<<'\n';
		}
		else{
			cout<<"IndSet"<<'\n';
			int now = 0;
			f1(n*3){
				if(!u[i]){
					cout<<i<<' ';
					now++;
				}
				if(now == n){
					break;
				}
			}
			cout<<'\n';
		}
	}
}