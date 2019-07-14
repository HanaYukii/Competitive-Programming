#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
 
int main(){
	int n;
	while(cin >> n){
		//n <<= 1;
		vector<int>v;
		int last = 0 ,f = 0;
		f(n){
			int add;
			cin >> add;
			v.pb(add);
			if(((add ^ last)&1) && last){
				f =1;
			}
			last = add;
		}
		if(f)
		sort(v.begin(),v.end());
		/*if(!f){
			cout << -1 << endl;
		}
		else{*/
			f(n){
				cout << v[i] << ' ';
			}
			cout << endl;
		//}
	}
}