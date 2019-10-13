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
	int u,d,l,r;
	cin >> l >> d >> r >> u;
	int u2,d2,l2,r2;
	cin >> l2 >> d2 >> r2 >> u2;
	int u3,d3,l3,r3;
	cin >> l3 >> d3 >> r3 >> u3;
	int f = 0;
	r--;
	r2--;
	r3--;
	for(int i=l;i<=r;i++){
		if(l2<=i&&r2>=i&&d2<=d&&u2>=u){
			continue;
		}
		if(l3<=i&&r3>=i&&d3<=d&&u3>=u){
			continue;
		}
		if(l3<=i&&r3>=i&&l2<=i&&r2>=i&&min(d2,d3)<=d&&max(u2,u3)>=u&&min(u2,u3)>=max(d2,d3)){
			continue;
		}
		f = 1;
		break;
	}
	if(f){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}