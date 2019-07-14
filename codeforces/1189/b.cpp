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
		vector<ll>v(n);
		f(n){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		if(v[1]+v[2]<=v[0]){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<v[1]<<' '<<v[0]<<' '<<v[2]<<' ';
			fr(j,3,n){
				cout<<v[j]<<' ';
			}
			cout<<endl;
		}
	}
}