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
	int n,k;
	while(cin >> n){
		
		int val[n+5] = {};
		f1(n){
			cin >> val[i];
		}
		cin >> k;
		int suf[k+5] = {};
		int last[n+5] = {};
		f1(k){
			int tp ;
			cin >> tp;
			if(tp == 1){
				int k,v;
				cin >> k >> v;
				val[k] = v;
				last[k] = i;
			}
			else{
				int v;
				cin >> v;
				suf[i] = v;
			}
		}
		for(int i=k-1;i>=0;i--){
			suf[i] = max(suf[i],suf[i+1]);
		}
		f1(n){
			cout<<max(val[i],suf[last[i]])<<' ';
		}
		cout << endl;
	}
}