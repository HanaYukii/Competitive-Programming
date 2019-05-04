#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	while(cin >> s){
		int last=0;
		for(int i=0;i<s.size();i++){
			if(s[i]!='0')last=i;
		}
		s=s.substr(0,last+1);
		string rev=s;
		reverse(s.begin(),s.end());
		//cout<<rev<<endl;
		if(s==rev){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
}