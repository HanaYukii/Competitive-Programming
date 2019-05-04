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

	string s1,s2;
	cin >> s1 >> s2;
	int sum1=0,sum2=0,q=0;
	for(auto i:s1){
		if(i=='+')sum1++;
	}
	for(auto i:s2){
		if(i=='+')sum2++;
		else if(i=='-'){

		}
		else q++;
	}
	ll cc,p2;
	p2=1<<q;
	cc=1;
	if(sum1<sum2||sum1-sum2>q){
		cout<<0<<endl;
		exit(0);
	}
	for(int i=1;i<=sum1-sum2;i++){
		cc *= q+1-i;
		cc /=i;
	}
	cout<<fixed<<setprecision(10)<<((double)cc/p2)<<endl;

}