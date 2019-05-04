#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int main(){
	ios_base::sync_with_stdio(0);
	int t,w;
	cin >> t>>w;
	while(t--){
		int fin[5]={};
		string s=" ";
		/*f(119){
			string add;
			cin >> add;
			s+=add;
		}*/
		string ans="";
		vector<int>pre;
		f(119)pre.pb(i);
		for(int j=1;j<=5;j++){
			vector<int>v[5];
			for(int i:pre){
				cout<<i*5+j<<endl;
				char c;
				cin >> c;
				//c=s[i*5+j];
				v[c-'A'].pb(i);
			}
			f(5){
				if(fin[i])continue;
				int need=1;
				for(int x=1;x<=5-j;x++){
					need *=x;
				}
				if(v[i].size()!=need){
					fin[i]=1;
					ans += (char)('A'+i);
					pre.clear();
					for(auto z:v[i]){
						pre.pb(z);
					}
					break;
				}
			}
		}

		cout<<ans<<endl;
		string k;
		cin >> k;
		if(k=="N")exit(0);
	}
}