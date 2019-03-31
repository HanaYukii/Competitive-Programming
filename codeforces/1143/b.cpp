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
	string s;
	while(cin >> s){
		int n=s.size();
		ll org=1;
		f(n){
			org*=s[i]-'0';
		}
		ll p=1;
		ll mx=org;
		ll mul=1;
		f(n-1)mul*=9;
		f(n){
			if(i==0&&s[i]=='1')
				mx=max(mx,mul);
			else
				mx=max(mx,p*(s[i]-'1')*mul);
			mul/=9;
			p*=s[i]-'0';
		}
		cout<<mx<<endl;
	}
}