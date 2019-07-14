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
struct a{
	int sx,sy;
	int ex,ey;
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int cont[n+5][m+5] = {};
		int mxx[30] = {};
		int mix[30] = {};
		int miy[30] = {};
		int mxy[30] = {};
		for(int i=1;i<30;i++){
			miy[i]=mix[i]=1e9;
		}
		int mx = 0;
		f1(n){
			string s;
			cin >> s;
			fr(j,1,m+1){
				if(s[j-1]=='.')continue;
				int num = s[j-1]-'a'+1;
				mx = max(mx,num);
				cont[i][j]=num;
				mxx[num] = max(mxx[num],i);
				mix[num] = min(mix[num],i);
				mxy[num] = max(mxy[num],j);
				miy[num] = min(miy[num],j);

			}
		}
		if(mx == 0){
			cout<<"YES"<<'\n';
			cout<<0<<'\n';
			continue;
		}
		int f = 0;
		vector<a>ans;
		f(30){
			if(mix[i]>1e5){
				mix[i]=miy[i]=0;
			}
		}
		for(int i=mx ; i >= 1 ;i--){
			//cout<<mix[i]<<' '<<mxx[i]<<' '<<mxy[i]<<' '<<miy[i]<<endl;
			if(mix[i]!=mxx[i]&&mxy[i]!=miy[i]){
				f=1;
				break;
			}
			//cout<<i<<' '<<mx << endl;
			if(mxx[i]==0&&i==mx){
				f=1;
				break;
			}
			if(mxx[i]==0){
				//cout<<"here"<<endl;
				a b=ans.back();
				int px=b.sx,py=b.sy;
				cont[py][px]=i;
				ans.pb(b);
			}
			else if(mix[i]==mxx[i]){
				for(int j=miy[i];j<=mxy[i];j++){
					if(cont[mix[i]][j]<i){
						f=1;
						break;
					}
					else{
						cont[mix[i]][j]=i;
					}
				}
				if(f)break;
				ans.pb({miy[i],mix[i],mxy[i],mix[i]});
			}
			else{
				for(int j=mix[i];j<=mxx[i];j++){
					if(cont[j][miy[i]]<i){
						f=1;
						break;
					}
					else{
						cont[j][miy[i]]=i;
					}
				}
				if(f)break;
				ans.pb({miy[i],mix[i],mxy[i],mxx[i]});
			}
		}
		if(f){
			cout<<"NO"<<'\n';
		}
		else{
			reverse(ans.begin(),ans.end());
			cout<<"YES"<<'\n';
			cout<<mx<<'\n';
			for(auto i:ans){
				cout<<i.sy<<' '<<i.sx<<' '<<i.ey<<' '<<i.ex<<'\n';
			}
		}
	}

}