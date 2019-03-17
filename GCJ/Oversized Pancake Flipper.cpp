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
	int t;
	cin>>t;
	for(int c=1;c<=t;c++){
		string s;
		cin>>s;
		int k;
		cin>>k;
		int n=s.size();
		int cont[n+5]={};
		for(int i=0;i<n;i++){
			if(s[i]=='+'){
				cont[i]=1;
			}
		}
		int cnt=0;
		for(int i=0;i<n-k+1;i++){

			if(!cont[i]){
				//cout<<i<<' '<<i+k-1<<endl;
				cnt++;
				for(int j=i;j<i+k;j++){
					cont[j]^=1;
				}
			}
		}
		int f=0;
		f(n){
			if(!cont[i]){
				f=1;
			}
		}
		if(!f){
			printf("Case #%d: %d\n",c,cnt);
		}
		else{
			printf("Case #%d: IMPOSSIBLE\n",c);
		}
	}
}