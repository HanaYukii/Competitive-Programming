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
#define pii pair<int,int>

int main(){
	int n;
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		set<int>st;
		vector<int>ans;
		f1(n)st.insert(i);
		int pre=0;
		f(n){
			int add;
			cin >> add;
			
			if(add!=-1){
				if(pre > add){
					cout<<-1<<endl;
					goto fin;
				}
				else if(*st.begin() >= add){
					cout<<-1<<endl;
					goto fin;
				}
				if(st.find(add-1) != st.end()){
					ans.pb(add-1);
					st.erase(add-1);
				}
				else{
					ans.pb(*st.begin());
					st.erase(st.begin());
				}
				pre = max(add,pre);
			}
			else{
				ans.pb(*st.begin());
				pre=max(pre,*st.begin()+1);
				st.erase(st.begin());
			}
		}
		for(auto i:ans){
			cout<<i<<' ';
		}
		cout<<endl;
		fin:;
	}
}