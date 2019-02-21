#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int main(){
	int n,m;
    while(cin>>n>>m){
    	int ans=0;
    	int can=0;
    	vector<ll>cont(n);
    	f(n)cin>>cont[i];
    	//cout<<"gg"<<endl;
    	sort(cont.begin(),cont.end());
    	reverse(cont.begin(),cont.end());
    	for(int i=1<<20;i;i>>=1){
    		//cout<<"gg"<<endl;
    		if(ans+i<=n){
    			//int f=0;
    			//cout<<"gg"<<endl;
    			ll cnt=0;
    			for(int j=0;j<n;j++){
    				cnt+=max(0LL,cont[j]-j/(ans+i));
    			}
    			//cout<<ans+i<<' '<<cnt<<endl;
    			if(cnt<m){
    				ans+=i;
    			}
    			else{
    				can=1;
    			}
    		}
    	}
    	if(!can)cout<<-1<<endl;
    	else cout<<ans+1<<endl;
    }
}