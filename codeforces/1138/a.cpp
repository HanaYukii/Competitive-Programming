#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const int maxn=200005;
int cont[maxn];
int main(void){
	ios_base::sync_with_stdio(false);
	int n,k;
	while(cin>>n){
		f(n){
			cin>>cont[i];
		}
		int pre=0,now=1;
		int mx=0;
		f1(n-1){
			if(cont[i]==cont[i-1]){
				now++;
				mx=max(mx,min(pre,now)*2);
			}
			else{
				pre=now;
				now=1;
				mx=max(mx,min(pre,now)*2);
			}
		}
		cout<<mx<<endl;
	}
}