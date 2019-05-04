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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,a,b;
	while(cin >>n>>a>>b){
		int rb=b;
		int cont[n+5]={};
		f(n)cin>>cont[i];
		f(n){
			if(cont[i]==1){
				if(rb==b){
					b--;
				}
				else{
					if(a){
						a--,b++;
					}
					else{
						if(!b){
							cout<<i<<endl;
							exit(0);
						}
						else{
							b--;
						}
					}
				}
			}
			else{
				if(b)b--;
				else if(a)a--;
				else {
					cout<<i<<endl;
					exit(0);
				}
			}
		}
		cout<<n<<endl;
	}

}