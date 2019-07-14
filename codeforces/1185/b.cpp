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
const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s1,s2;
		cin >> s1 >> s2;
		int n=s1.size(),m=s2.size();
		int now = 0;
		int f = 0;
		for(int i=0;i<n;i++){
			if(s2[now]!=s1[i]){
				f=1;
				break;
			}
			else if(i==n-1){
				while(now<m){
					if(s2[now]==s1[i]){
						now++;
					}
					else{
						break;
					}
				}
			}
			else{
				if(s1[i+1]==s1[i]){
					now++;
				}
				else{
					while(now<m){
						if(s2[now]==s1[i]){
							now++;
						}
						else{
							break;
						}
					}
				}
			}
		}
		if(now!=m)f=1;
		if(f){
			cout<<"NO"<<'\n';
		}
		else{
			cout<<"YES"<<'\n';
		}
	}

}