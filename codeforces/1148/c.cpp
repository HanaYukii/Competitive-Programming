#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
vector<pair<int,int> > op;

int p[300005] = {};
int rev[300005] = {};
int cont[300005] = {};
void swapp(int a,int b){
	int num1 = p[a];
	int num2 = p[b];
	p[a] = num2;
	p[b] = num1;
	rev[num2] = a;
	rev[num1] = b;
	op.pb({a,b});
	swap(cont[a],cont[b]);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;//,m,k,ta,tb;
	while(cin >> n ){
		op.clear();
		ms(p);
		ms(rev);
		int tt[n+5]={};
		f1(n){
			int add;
			cin >> add;
			cont[i] = tt[i]=add;
			p[i] = add;
			rev[add] = i;
		}
		f1(n){
			if(p[i] == i)continue;
			if(rev[i] - i >= n/2){
				swapp(i,rev[i]);
			}
			else{
				if(i-1>=n/2){
					int tmp=rev[i];
					swapp(rev[i],1);
					swapp(1,i);
					swapp(1,tmp);
				}
				else{
					if(n-rev[i]>=n/2){
						swapp(rev[i],n);
						swapp(n,i);
					}
					else{
						int tmp=rev[i];
						swapp(rev[i],1);
						swapp(1,n);
						swapp(n,i);
						swapp(tmp,1);
					}
				}
			}
		}
		cout << op.size()<<'\n';
		for(auto i:op){
			cout << i.first<<' '<<i.second << '\n';
		}
	}
	
}