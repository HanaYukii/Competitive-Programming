#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
struct e{
	int l;
	int r;
	int idx;
	int f;
}cont[100005];
bool cmp(e x,e y){
	if(x.l!=y.l)
		return x.l<y.l;
	else
		return x.r<y.r;
}
bool cmp2(e x,e y){
	return x.idx<y.idx;
}
int main(void){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int nx=0,ny=0;
	while(t--){
		char c;
		cin>>c;
		if(c=='+'){
			int add1,add2;
			cin>>add1>>add2;
			if(add1>add2){
				swap(add1,add2);
			}
			nx=max(nx,add1);
			ny=max(ny,add2);
		}
		else{
			int add1,add2;
			cin>>add1>>add2;
			if(nx<=add1&&ny<=add2){
				cout<<"YES"<<endl;
			}
			else if(nx<=add2&&ny<=add1){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}

	}
}