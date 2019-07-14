#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
 
int main()
{
    
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin >> n >> k;
		ll cnt = 0;
		while(n!=0){
			if(n%k==0){
				cnt++;
				n/=k;
			}
			else{
				cnt+=n%k;
				n-=(n%k);
			}
			//cnt ++;
		}
		cout << cnt << endl;
	}
 
}