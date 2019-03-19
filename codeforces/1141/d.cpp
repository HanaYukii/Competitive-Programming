#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]
queue<int>l[27],r[27];
vector<pair<int,int> >ans;
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		string s1,s2;
		cin>>s1>>s2;
		ans.clear();
		f(27){
			while(!l[i].empty()){
				l[i].pop();
			}
			while(!r[i].empty()){
				r[i].pop();
			}
		}
		for(int i=0;i<n;i++){
			if(s1[i]=='?'){
				l[26].push(i+1);
			}
			else{
				l[s1[i]-'a'].push(i+1);
			}
			if(s2[i]=='?'){
				r[26].push(i+1);
			}
			else{
				r[s2[i]-'a'].push(i+1);
			}
		}
		f(26){
			while(!l[i].empty()&&!r[i].empty()){
				ans.pb({l[i].front(),r[i].front()});
				l[i].pop();r[i].pop();
			}
		}
		f(26){
			while(!l[i].empty()&&!r[26].empty()){
				ans.pb({l[i].front(),r[26].front()});
				l[i].pop();r[26].pop();
			}
		}
		f(26){
			while(!l[26].empty()&&!r[i].empty()){
				ans.pb({l[26].front(),r[i].front()});
				l[26].pop();r[i].pop();
			}
		}
		while(!l[26].empty()&&!r[26].empty()){
				ans.pb({l[26].front(),r[26].front()});
				l[26].pop();r[26].pop();
		}
		cout<<ans.size()<<endl;
		for(auto i:ans){
			cout<<i.first<<' '<<i.second<<endl;
		}
	}
		
		
}