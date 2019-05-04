#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >>n){
		int cont[n+5]={};
		set<int>st;
		f(n)cin >> cont[i];
		f(n)st.insert(cont[i]);
		vector<int>v;
		for(auto i:st){
			v.pb(i);
		}
		if(v.size()==1){
			cout<<0<<endl;
		}
		else if(v.size()==2){
			if((v[1]-v[0])%2==0){
				cout<<(v[1]-v[0])/2<<endl;
			}
			else{
				cout<<v[1]-v[0]<<endl;
			}
		}
		else if(v.size()==3){
			if(v[2]-v[1]==v[1]-v[0]){
				cout<<v[1]-v[0]<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else{
			cout<<-1<<endl;
		}

	}

}