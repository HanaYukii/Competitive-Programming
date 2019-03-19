#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]

int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		//int first=0;
		int cont[n+5]={};
		f(n){
			cin>>cont[i];
		}
		int pre=0;
		f(n){
			if(cont[i]==1){
				pre++;
			}
			else{
				break;
			}
		}
		int ans=0,now=0;
		f(n){
			if(cont[i]==1){
				now++;
			}
			else{
				ans=max(ans,now);
				now=0;
			}
		}
		ans=max(min(n,now+pre),ans);
		cout<<ans<<endl;
	}
		
		
}