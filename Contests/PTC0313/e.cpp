#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int lis[5005];
int lds[5005];
void LIS(vector<ll> &v)
{
    vector <ll> ve;
    ve.push_back(v[0]);
    lis[0]=1;
    for(int i=1;i<(int)v.size();i++)
    {
        if(v[i]>ve.back()){
            ve.push_back(v[i]);
            lis[i]=ve.size();
        }
        else{
        	
            *lower_bound(ve.begin(),ve.end(),v[i])=v[i];
            lis[i]=lower_bound(ve.begin(),ve.end(),v[i])-ve.begin()+1;
        }
    }
    //return ve.size();
}
void LDS(vector<ll> &v)
{
    vector <ll> ve;
    ve.push_back(v[0]);
    lds[0]=1;
    for(int i=1;i<(int)v.size();i++)
    {
        if(v[i]>ve.back()){
            ve.push_back(v[i]);
            lds[i]=ve.size();
        }
        else{
        	
            *lower_bound(ve.begin(),ve.end(),v[i])=v[i];
            lds[i]=lower_bound(ve.begin(),ve.end(),v[i])-ve.begin()+1;
        }
    }
    //return ve.size();
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ms(lis);ms(lds);
		int n;
		cin>>n;
		if(!n){
			cout<<0<<endl;
			continue;
		}
		vector<ll>cont;
		f(n){
			ll add;
			cin>>add;
			cont.pb(add);
		}
		reverse(cont.begin(),cont.end());
		for(int i=0;i<n;i++){
			lis[i]=1;
			lds[i]=1;
			for(int j=0;j<i;j++){
				if(cont[i]>cont[j]){
					lis[i]=max(lis[i],lis[j]+1);
				}
				if(cont[i]<cont[j]){
					lds[i]=max(lds[i],lds[j]+1);
				}
			}
		}
		int mx=0;
		f(n){
			mx=max(mx,lis[i]+lds[i]-1);
		}
		cout<<mx<<endl;
	}
}