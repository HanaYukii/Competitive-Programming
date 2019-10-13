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
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if(n%2==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		vector<int>v1,v2;
		int f = 0;
		for(int i=1;i<n*2;i+=2){
			if(f){
				v1.pb(i);
				v2.pb(i+1);
			}
			else{
				v1.pb(i+1);
				v2.pb(i);
			}
			f^=1;
		}
		for(auto i:v2){
			v1.pb(i);
		}
		for(auto i:v1){
			cout<<i<<' ';
		}
		cout << endl;
	}
	
}