#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
bool check(int x){
	int v[10] = {};
	while(x){
		if(v[x%10]){
			return 0;
		}
		v[x%10] = 1;
		x /= 10;
	}
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int l,r;
	cin >> l >> r;
	fr(i,l,r+1){
		if(check(i)){
			cout<<i<<endl;
			exit(0);
		}
	}
	cout<<-1<<endl;
}