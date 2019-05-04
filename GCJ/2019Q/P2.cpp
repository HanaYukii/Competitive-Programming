#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));

int main(){
	int t;
	cin >> t;
	for(int c = 1 ; c <=t;c++){
		int n;
		cin >> n;
		string s;
		cin >> s;
		for(auto &i:s){
			if(i=='S'){
				i='E';
			}
			else{
				i='S';
			}
		}
		printf("Case #%d: ",c );
		cout<<s<<endl;
	}
}