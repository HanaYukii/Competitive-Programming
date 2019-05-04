#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

struct op
{
	int tp;
	int l,r;
};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,a,b;
	while(cin >> n >> a >> b){
		int cont[n+5] = {};
		f1(n){
			cin >> cont[i];
		}
		vector<op>v;
		f(a){
			op add;
			cin >> add.tp >> add.l >> add.r;
			v.pb(add);
		}
		reverse(v.begin(),v.end());
		f(b){
			int k;
			cin >> k;
			for(auto j:v){
				if(k>j.r||k<j.l){
					continue;
				}
				if(j.tp==1){
					if(k==j.l)k=j.r;
					else k--;
				}
				else{
					k=j.l+j.r-k;
				}
			}
			cout<<cont[k]<<' ';
		}
		cout<<endl;
	}
	
}