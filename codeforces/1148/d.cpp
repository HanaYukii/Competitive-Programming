#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
struct pp{
	int ff,xx;
	int idx;
};
bool cmp(pp x,pp y){
	return x.ff<y.ff;
}
bool cmp2(pp x,pp y){
	return x.xx>y.xx;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;//,m,k,ta,tb;
	while(cin >> n ){
		vector<pp>u,d;
		f(n){
			int add1,add2;
			cin >> add1 >> add2;
			if(add1 > add2){
				pp add;
				add.ff=add1;
				add.xx=add2;
				add.idx = i+1;
				d.pb(add);
			}
			else{
				pp add;
				add.ff=add1;
				add.xx=add2;
				add.idx = i+1;
				u.pb(add);
			}
		}
		sort(d.begin(),d.end(),cmp);
		sort(u.begin(),u.end(),cmp2);
		if(d.size()>u.size()){
			cout << d.size() << endl;
			for(auto i:d){
				cout <<i.idx<<' ';
 			}
 			cout << endl;
		}
		else{
			cout << u.size() << endl;
			for(auto i:u){
				cout <<i.idx<<' ';
 			}
 			cout << endl;
		}
	}
	
}