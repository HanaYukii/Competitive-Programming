#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	int cont[maxn];
	while(cin>>n>>k){
		f(n){
			cin>>cont[i];
		}
		int fin=-1;
		int cnt=0;
		while(fin<n-1){
			int f=0;
			int ans=0;
			for(int i=max(fin+2-k,0);i<min(fin+1+k,n);i++){
				//cout<<i<<endl;
				if(cont[i]){
					ans=i;
					f=1;
				}
			}
			if(!f){
				cout<<-1<<endl;
				exit(0);
			}
			cnt++;
			fin=ans+k-1;
		}
		cout<<cnt<<endl;
	}
}