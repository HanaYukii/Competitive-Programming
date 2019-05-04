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
	int n;
	string s;
	while(cin >> s){
		n=s.size();
		int cnt=0;
		for(auto i:s){
			if(i=='a')cnt++;
		}
		cout<<min(cnt*2-1,n)<<endl;
	}

}