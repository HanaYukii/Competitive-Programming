#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
bool cp(string s){
	int n=s.size();
	f(n/2){
		if(s[i]!=s[n-1-i])return 0;
	}
	return 1;
}
int main(){
	int n;
	string s;
	while(cin>>s){
		n=s.size();
		for(int i=1;i<=n-1;i++){
			if(s.substr(i,n-i)+s.substr(0,i)!=s){
				if(cp(s.substr(i,n-i)+s.substr(0,i))){
					cout<<1<<endl;
					exit(0);
				}
			}
		}
		if(n<=3){
			cout<<"Impossible"<<endl;
			exit(0);
		}
		if(n&1){
			char st=s[0];
			for(int i=0;i<n;i++){
				if(s[i]!=st&&i!=n/2){
					cout<<2<<endl;
					exit(0);
				}
			}
			cout<<"Impossible"<<endl;
			exit(0);
		}
		else{
			char st=s[0];
			for(int i=0;i<n;i++){
				if(s[i]!=st){
					cout<<2<<endl;
					exit(0);
				}
			}
			cout<<"Impossible"<<endl;
			exit(0);
		}
	}
}