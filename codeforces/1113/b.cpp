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
		int cont[n+5]={};
		int mp=0;
		int Min=1e9;
		int sum=0;
		f(n){
			scanf("%d",&cont[i]);
			sum+=cont[i];
			if(cont[i]<Min){
				Min=cont[i];
				mp=i;
			}
		}
		int Max=0;
		f(n){
			if(i==mp){
				continue;
			}
			for(int j=2;j<=min(cont[i],10);j++){
				if(cont[i]%j==0){
					Max=max(Min+cont[i]-Min*j-cont[i]/j,Max);
				}
			}
		}
		cout<<sum-Max<<endl;
	}
}