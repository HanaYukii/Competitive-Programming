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
		string t;
		for(auto i:s){
			if(i!='a'){
				t+=i;
			}
		}
		if(t.size()&1){
			cout<<":("<<endl;
			exit(0);
		}
		string s1=t.substr(0,t.size()/2);
		string s2=t.substr(t.size()/2,t.size()/2);
		//cout<<s.substr(s.size()-t.size()/2,t.size()/2)<<endl;
		if(s1!=s2){
			cout<<":("<<endl;
			exit(0);
		}
		else if(s.substr(s.size()-t.size()/2,t.size()/2)!=s2){
			cout<<":("<<endl;
			exit(0);
		}
		cout<<s.substr(0,s.size()-t.size()/2)<<endl;
	}

}