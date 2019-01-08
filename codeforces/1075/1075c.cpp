#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define maxn 200005
#define endl '\n'
#define pb push_back
map<int,int>cnt;
int x[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	ll n,m;
	while(cin>>n){
		for(int i=2;i<=n;i++){
			cin>>x[i];
		}
		stack<int>s;
		s.push(n);
		while(1){
			n=x[n];
			s.push(n);
			if(n==1)break;
		}
		while(!s.empty()){
			cout<<s.top()<<' ';
			s.pop();
		}
		cout<<endl;
	}
}