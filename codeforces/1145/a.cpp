#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		int cont[n+5]={};
		int k=n;
		f(n){
			cin>>cont[i];
		}
		while(n){
			for(int i=0;i<k;i+=n){
				int f=0;
				for(int j=i+1;j<i+n;j++){
					if(cont[j]<cont[j-1]){
						f=1;
						break;
					}
				}
				if(!f){
					cout<<n<<endl;
					exit(0);
				}
			}
			n>>=1;
		}
	}

}