#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back

int main(){
	ll x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2){
    	string s;
    	int n;
    	cin>>n;
    	cin>>s;
    	ll prex[n+5]={};
    	ll prey[n+5]={};
    	if(s[0]=='U'){
    		prey[1]=1;
    		prex[1]=0;
    	}
    	else if(s[0]=='D'){
    		prey[1]=-1;
    		prex[1]=0;
    	}
    	else if(s[0]=='L'){
    		prey[1]=0;
    		prex[1]=-1;
    	}
    	else if(s[0]=='R'){
    		prey[1]=0;
    		prex[1]=1;
    	}
    	fr(i,2,n+1){
    		if(s[i-1]=='U'){
    			prey[i]=prey[i-1]+1;
    			prex[i]=prex[i-1];
    		}
    		else if(s[i-1]=='D'){
    			prey[i]=prey[i-1]-1;
    			prex[i]=prex[i-1];
    		}
    		else if(s[i-1]=='L'){
    			prey[i]=prey[i-1];
    			prex[i]=prex[i-1]-1;
    		}
    		else if(s[i-1]=='R'){
    			prey[i]=prey[i-1];
    			prex[i]=prex[i-1]+1;
    		}
    	}
    	ll ans=0;
    	int f=0;
    	for(ll i=1LL<<50;i;i>>=1){
    		ll now=ans+i;
    		ll nowx=x1+prex[n]*(now/n)+prex[(now)%n];
    		ll nowy=y1+prey[n]*(now/n)+prey[(now)%n];
    		ll dis=abs(nowx-x2)+abs(nowy-y2);
    		if(dis<=now){
    			f=1;
    		}
    		else{
    			ans+=i;
    			//cout<<now<<' '<<nowx<<' '<<nowy<<endl;
    		}
    	}
    	if(!f){
    		cout<<-1<<endl;
    	}
    	else{
    		cout<<ans+1<<endl;
    	}
    }
}