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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >>n){
		string s;
		cin>>s;
		int Min=1e9;
		int cmp[4]={0,2,19,6};
		for(int i=0;i<=n-4;i++){
			int sum=0;
			for(int j=0;j<4;j++){
				int now=s[j+i]-'A';
				//cout<<now<<endl;
				sum+=min({abs(now-cmp[j]),abs((now+26)-cmp[j]),abs((now-26)-cmp[j])});
			}
			Min=min(Min,sum);
		}
		cout<<Min<<endl;
	}

}