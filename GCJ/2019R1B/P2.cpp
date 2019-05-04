#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) fset(i,0,sizeof(i));
#define ms1(i) fset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
#define pii pair<int,int>
#include<iostream>
using namespace std;


int main()
{
	int t,w;
	cin >> t>>w;
    for (int c = 1 ;c <= t;c++)
    {
       	ll ans[6]= {};
       	for(int i=5;i>=1;i--){
       		cout<<i*63<<endl;
       		ll add;
       		cin >> add;
       		if(add==-1)exit(0);
       		for(int j=i+1;j<6;j++){
       			add -= ans[j]*(1LL<<(i*63)/(j+1));
       		}
       		ans[i]=(add)/(1LL<<(i*63)/(i+1));
       	}
       	cout<<1<<endl;
       	ll add;
       	cin >> add;
       	f1(5){
       		add -= ans[i];
       	}
       	add >>=1;
       	ans[0] = add;
       	f(6){
       		cout<<ans[i]<<' ';
       	}
       	cout<<endl;
       	int f;
       	cin >> f;
       	if(f==-1)exit(0);
	}
    return 0;
}
