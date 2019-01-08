#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define lg length()
#define endl '\n'
using namespace std;
int cont[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	string s;
	while(cin>>s){
		int ans[1005]={};
		int now=1;
		if(s[s.length()-1]=='a'){
			ans[s.length()-1]=1;
			now=0;
		}
		for(int i=s.length()-2;i>=0;i--){
			if(s[i]-'a'!=now){
				ans[i]=1;
				now^=1;
			}
		}
		f((int)s.length()){
			cout<<ans[i]<<' ';
		}
		cout<<endl;
	}
}	
