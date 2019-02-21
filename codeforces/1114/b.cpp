#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
struct s{
	ll num,idx;
}cont[maxn];
bool cmp(s x,s y){
	return x.num>y.num;
}
int main(){
	int n,m,k;
	while(cin>>n>>m>>k){
		f(n){
			cin>>cont[i].num;
			cont[i].idx=i;
		}
		sort(cont,cont+n,cmp);
		set<int>st;
		ll sum=0;
		f(m*k){
			st.insert(cont[i].idx);
			sum+=cont[i].num;
		}
		cout<<sum<<endl;
		int now=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(cnt==k-1)break;
			if(st.find(i)!=st.end()){
				now++;
				if(now==m){
					cout<<i+1<<' ';
					now=0;
					cnt++;
				}
			}
		}
		cout<<endl;
	}
}