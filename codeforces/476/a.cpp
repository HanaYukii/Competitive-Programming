#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
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

	int n,m;
	while(cin >> n >> m){
		if(n<m)cout<<-1<<endl;
		else{
			int Min=n/2+(n&1); 
			if(Min%m==0){
				cout << Min << endl;
			}
			else{
				cout<<(Min/m+1)*m<<endl;
			}
		}
	}
}