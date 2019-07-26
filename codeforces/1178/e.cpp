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
#define F first
#define S second
const ll mod = 998244353;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	while(cin >> s){
		n = s.size();
		string s1,s2;
		string mid = "";
		if(n%4){
			mid += s[n/2];
			s1 = s.substr(0,n/2);
			s2 = s.substr(n/2+1,n-n/2-1);
		}
		else{
			s1 = s.substr(0,n/2);
			s2 = s.substr(n/2,n/2); 
		}
		reverse(s1.begin(),s1.end());
		int sz = min(s1.size(),s2.size());
		vector<char>ans;
		for(int i=0;i+1<sz;i+=2){
			int cnt[3] = {};
			cnt[s1[i]-'a']++;
			cnt[s1[i+1]-'a']++;
			cnt[s2[i]-'a']++;
			cnt[s2[i+1]-'a']++;
			if(cnt[0]>=2){
				ans.pb('a');
			}
			else if(cnt[1]>=2){
				ans.pb('b');
			}
			else{
				ans.pb('c');
			}
		}
		reverse(ans.begin(),ans.end());
		for(auto i:ans){
			cout<<i;
		}
		cout<<mid;
		while(ans.size()){
			cout<<ans.back();
			ans.pop_back();
		}
		cout << endl;

	}
}