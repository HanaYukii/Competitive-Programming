#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
int bit[maxn];
void update(int x){
	while(x < maxn ){
		bit[x]++;
		x+=(x & (-x) );
	}
}
ll sum(int x){
	ll ret = 0;
	while(x){
		ret += bit[x];
		x -= (x&(-x));
	}
	return ret;
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	int cnt = 0;
	map<int,string>mp;
	map<string,int>ans;
	while(getline(cin,str)){
		stringstream ss(str);
		string add;
		while(ss >> add){
			string now="";
			for(auto i:add){
				if(i >= 'a' && i <= 'z'){
					now += i;
				}
				else if(i >= 'A' && i <= 'Z'){
					now += (char)('a'+(i-'A'));
				}
			}
			if(now.size()){
				if(ans.find(now) == ans.end())
					mp[cnt++] = now;
				ans[now]++;
			}
		}
	}
	for(auto i:mp){
			cout << i.second << ' ' << ans[i.second] << '\n';
	}
}