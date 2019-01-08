#include<bits/stdc++.h>
#define pb push_back
#define pb push_back
#define ll long long
#define maxn 400005
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
	string s;
	int n;
	while(cin>>n){
		cin>>s;
		int f=0;
		for(int i=0;i<s.length();i++){
			if(s[i]!=s[0]){
				f=1;
			}
		}
		if(!f){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i=0;i<s.length()-1;i++){
				if(s[i]!=s[i+1]){
					cout<<s.substr(i,2)<<endl;
					break;
				}
			}
		}
	}	
}