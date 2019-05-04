#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int ans[1035]={0};
int bi[10]={1,2,4,8,16,32,64,128,256,512};
int main(){
	int t;
	string s;
	getline(cin,s);
	stringstream ss(s);
	ss >> t;
	while(t--){
		int n,b,f;
		getline(cin,s);
		stringstream ff(s);
		ff >> n >> b >> f;
		ms(ans);
		b=n-b;

		for(int i=0;i<5;i++){
			string g;
			for(int j=0;j<n;j++){
				if(j&bi[i]){
					g+='1';
				}
				else{
					g+='0';
				}
			}
			cout<<g<<endl;
			fflush(stdout);
			string s;
			getline(cin,s);
			for(int j=0;j<(int)s.size();j++){
				if(s[j]=='1'){
					//cout<<s.size()<<' '<<j<<' '<<bi[i]<<endl;
					//cout<<j<<' '<<ans[j]<<endl;
					ans[j] += bi[i];
					//cout<<j<<' '<<ans[j]<<endl;
				}
			}
		}

		set<int>st;
		st.clear();
		int add = 0;
		int adj[1030]={};
		for(int i=1;i<b;i++){
			if(ans[i]<=ans[i-1]){
				add += 32;
			}
			adj[i] += add;
		}
		f(b){
			//cout<<i<<' '<<ans[i]<<endl;
			st.insert(ans[i]+adj[i]);
		}
		string ret="";
		f(n){
			if(st.find(i)==st.end()){
				ret += " ";
				ret+=to_string(i);
				ret += " ";
			}
			
		}
		cout<<ret<<endl;
		fflush(stdout);
		string v;
		getline(cin,v);
		if(v == "-1")exit(0);
	}
	exit(0);
}