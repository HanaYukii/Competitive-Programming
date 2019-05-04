#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
#define pii pair<int,int>

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >>n){
		int cont[n+5] = {};
		f(n){
			cin >> cont[i];
		}
		f(n-1){
			if((cont[i]==2&&cont[i+1]==3)||(cont[i]==3&&cont[i+1]==2)){
				cout<<"Infinite"<<endl;
				exit(0);
			}
		}
		int sum=0;
		for(int i=0;i<n;i++){
			if(cont[i]!=1)continue;
			if(i==0){
				sum += cont[i+1]+1;
			}
			else if(i==n-1){
				sum += cont[i-1]+1;
			}
			else{
				sum += cont[i-1]+cont[i+1]+2;
				if(cont[i-1]==3&&cont[i+1]==2){
					sum--;
				}
			}
		}
		cout<<"Finite"<<endl;
		cout<<sum<<endl;
	}

}