#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll cont[105],n;
ll mod=54018521;

ll fast(ll x,ll p){
	ll ret=1;
	ll now=x;
	while(p){
		if(p&1){
			ret*=now;
			ret%=mod;
		}
		p>>=1;
		now*=now;
		now%=mod;
	}
	return ret;
}

ll cal(ll x){
	ll ret=0;
	for(int i=0;i<n;i++){
		ret+=(fast(x,n-1-i)*(cont[i]%mod))%mod;
		ret%=mod;
	}
	
	return ret;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ms(cont);
		//int n;
		cin>>n;
		f(n){
			cin>>cont[i];
		}
		set<ll>can;
		vector<ll>ans;
		can.clear();
		ans.clear();
		can.insert(0);
		int fnz=0;
		if(cont[n-1]==0){
			can.insert(0);
		}
		for(int i=n-1;i>=0;i--){
			if(cont[i]!=0){
				fnz=cont[i];
				break;
			}
		}
		f(n){
			cont[i]+=mod;
			cont[i]%=mod;
		}
		for(int i=1;i<=(ll)sqrt(abs(fnz));i++){
			if(fnz%i==0){
				if(i*i==fnz){
					can.insert(i);
					can.insert(-i);
				}
				else{
					can.insert(i);
					can.insert(-i);
					can.insert(fnz/i);
					can.insert(-(fnz/i));
				}
			}
		}
		
		for(std::set<ll>::iterator i=can.begin();i!=can.end();++i){
			int k=(*i+mod)%mod;
			if(cal(k)==0){
				ans.pb(*i);
			}
		}
		if(ans.size()==0){
			cout<<"No"<<endl;
		}
		else{
			cout<<"Yes"<<endl;
			sort(ans.begin(),ans.end());
			for(int i=0;i<(int)ans.size();i++){
				if(i!=(int)ans.size()-1){
					cout<<ans[i]<<' ';
				}
				else{
					cout<<ans[i]<<endl;
				}
			}
			//cout<<endl;
		}
	}
}