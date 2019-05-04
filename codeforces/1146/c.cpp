#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin >>n;
		int time=0;
		for(int i=0;i<10;i++){
			if((1<<i)<n)time++;
			else break;
		}
		int mx=0;
		int gap=1;
		while(time--){
			vector<int>v1,v2;
			int now=0;
			for(int i=1;i<=n;i+=gap){
				for(int j=i;j<min(i+gap,n+1);j++){
					if(now)v1.pb(j);
					else v2.pb(j);
				}
				now^=1;
			}
			cout<<v1.size()<<' '<<v2.size()<<' ';
			for(auto i:v1){
				cout<<i<<' ';
			}
			for(auto j:v2){
				cout<<j<<' ';
			}
			cout<<endl;
			int add;
			cin >> add;
			mx=max(mx,add);
			gap <<=1;
		}
		cout<<-1<<' '<<mx<<endl;
	}

}