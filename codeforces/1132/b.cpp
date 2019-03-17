#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	int n;
	while(cin>>n){
		ll cont[n+5]={};
		ll pre[n+5];
		f(n){
			cin>>cont[i];
		}
		sort(cont,cont+n);
		pre[0]=cont[0];
		f1(n-1){
			pre[i]=pre[i-1]+cont[i];
		}
		int k;
		cin>>k;
		while(k--){
			int add;
			cin>>add;
			cout<<pre[n-1]-cont[n-add]<<endl;
		}
	}
}