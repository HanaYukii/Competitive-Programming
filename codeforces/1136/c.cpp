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
	int n,m;
	while(cin>>n>>m){
		multiset<int>s1[1005],s2[1005];
		f1(n){
			fr(j,1,m+1){
				int add;
				cin>>add;
				s1[i+j].insert(add);
			}
		}
		f1(n){
			fr(j,1,m+1){
				int add;
				cin>>add;
				s2[i+j].insert(add);
			}
		}
		f1(n+m){
			if(s1[i]!=s2[i]){
				cout<<"NO"<<endl;
				exit(0);
			}
		}
		cout<<"YES"<<endl;
	}
}