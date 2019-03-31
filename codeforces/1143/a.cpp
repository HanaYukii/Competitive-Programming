#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));


int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		int m0=0,m1=0;
		f1(n){
			int add;
			cin >> add;
			if(add){
				m1=max(m1,i);
			}
			else{
				m0 = max(m0,i);
			}
		}
		cout<<min(m1,m0)<<endl;
	}
}