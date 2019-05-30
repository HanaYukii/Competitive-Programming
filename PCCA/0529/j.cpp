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
	ll k;
	while(cin >> k){
		int f=0;
		string s;
		char nc='b';
		while(k){
			if(k==1){
				s+="z";break;
			}
			ll x=0;
			if(!f){
				for(ll i=1<<15;i;i>>=1){
					ll now =x + i;
					if((1+now)*(now)/2+now/2+2<=k){
						x += i;
					}
				}
			}
			else{
				for(ll i=1<<15;i;i>>=1){
					ll now =x + i;
					if((1+now)*(now)/2+now/2*2+2<=k){
						x += i;
					}
				}
			}
			//cout<<(1+x)*(x)/2+x/2*2+2<<endl;
			if(!f){
				k -= (1+x)*(x)/2+x/2+2;
			}
			else{
				k -= (1+x)*(x)/2+x/2*2+2;
			}
			f(x){
				s +='a';
			}
			s+=nc;
			s+=nc+1;
			nc += 2;
			//cout<<x<<' '<<k<<endl;
			f = 1;
			if(k<'z'-nc){
				f1(k){
					s += nc+i;
				}
				break;
			}
		}
		cout << s << endl;
		/*int ans = 0;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++){
				int cnt[26]={};
				for(int k=i;k<=j;k++){
					cnt[s[k]-'a']++;
				}
				int f = 0;
				fr(k,0,26){
					if(cnt[k]&1)f++;
				}
				if(f<2)ans++;
			}
		}
		cout << ans << endl;*/
	}
}