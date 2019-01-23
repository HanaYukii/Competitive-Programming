#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
int main(void){
	ios_base::sync_with_stdio(false);
	int n,k;
	while(cin>>n>>k){
		string s;
		cin>>s;
		int Max=0;
		for(int i=0;i<26;i++){
			int cnt=0,now=0;
			for(int j=0;j<s.size();j++){
				if(s[j]-'a'==i){
					now++;
				}
				else{
					now=0;
				}
				if(now==k){
					cnt++;
					now=0;
				}
			}
			Max=max(Max,cnt);
		}
		cout<<Max<<endl;
	}
}