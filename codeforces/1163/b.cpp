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
	int n,m;
	while(cin >> n ){
		int cnt[100005]={};
		int num[100005]={};
		set<int>in;
		int ans=1;
		int pre=0;
		int f=0;
		f1(n){
			int add;
			cin >> add;
			if(pre==0){
				pre=add;
			}
			else if(pre!=add){
				f=1;
			}
			if(!f){
				ans=i;
			}
			cnt[add]++;
			num[cnt[add]-1]--;
			//cout<<num[cnt[add]-1]<<endl;
			if(num[cnt[add]-1]==0){
				in.erase(cnt[add]-1);
			}
			num[cnt[add]]++;
			in.insert(cnt[add]);
			/*for(auto j:in){
				cout<<j<<' ';
			}
			cout<<endl;*/
			if(in.size()==1){
				if(*in.begin()==1)
					ans = i;
			}
			else if(in.size()==2){
				int a=0,b=0;
				for(auto j:in){
					if(a==0)a=j;
					else b=j;
				}
				//cout<<a<<' '<<b<<' '<<num[a]<<' '<<num[b]<<endl;
				if(b-1==a&&num[b]==1){
					ans=i;
				}
				else if(num[1]==1){
					ans=i;
				}
			}
		}
		cout<<ans<<endl;
	}
}