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
		string s;
		cin >> s;
		int pl = 0;
		for(auto i:s){
			if(i=='0')pl++;
			else pl--;
		}
		if(pl == 0){
			cout<<2<<endl;
			cout<<s.substr(0,1)<<' '<<s.substr(1,n-1)<<endl;
		}
		else{
			cout<<1<<endl;
			cout<<s<<endl;
		}
	}
}