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
	int n;
	while(cin >> n){
		int cont[n+5] = {};
		int ans[n+5] = {};
		int inc=-1e9,dec=1e9;
		f(n){
			cin >> cont[i];
		}
		f(n){
			if(cont[i]>inc&&cont[i]<dec){
				if(cont[i+1]<cont[i]){
					dec=cont[i];
					ans[i] = 1;
				}
				else{
					inc = cont[i];
				}
			}
			else if(cont[i] > inc){
				inc = cont[i];
			}
			else if(cont[i] < dec){
				dec = cont[i];
				ans[i] = 1;
			}
			else{
				cout<<"NO"<<endl;
				exit(0);
			}
		}
		cout<<"YES" << endl;
		f(n){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}


}