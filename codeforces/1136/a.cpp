#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int maxn=1005;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
		int l[105];
		int r[105];
		f(n)cin>>l[i]>>r[i];
		int k;
		cin>>k;
		for(int i=0;i<n;i++){
			if(k<=r[i]){
				cout<<n-i<<endl;
				break;
			}
		}
	}
}