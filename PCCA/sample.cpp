#include<bits/stdc++.h>
#include <sys/time.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=998244353;
vector<int>g[maxn];
long long sz[maxn];
void dfs(int now,int pre){
	sz[now]=1;
	for(auto i:g[now]){
		if(i!=pre){
			dfs(i,now);
			sz[now]+=sz[i];
		}
	}
}
int main()
{
    int n,k;
    struct timeval start,endd;
    gettimeofday(&start, 0);
    ios_base::sync_with_stdio(false);
    cin.tie(0);	
    int t;
    cin>>t;

    while(t--){
        memset(sz,0,sizeof(sz));
        cin>>n>>k;
    	for(int i=0;i<=n;i++)
    		g[i].clear();
    	for(int i=0;i<n-1;i++){
    		int add1,add2;
    		cin>>add1>>add2;
    		g[add1].pb(add2);
    		g[add2].pb(add1);
    	}
        vector<long long>w;
        for(int i=0;i<k;i++){
            ll add;
            cin>>add;
            w.push_back(add);
        }
        sort(w.begin(),w.end());
        reverse(w.begin(),w.end());
    	dfs(1,0);
    	for(int i=1;i<=n;i++){
            sz[i]=sz[i]*(n-sz[i]);
        }
        sort(sz+2,sz+n+1);
        for(int i=2;i<=n;i++){
            sz[i]%=mod;
        }
        ll ans=0;
        int pos=2;
        for(auto i:w){
            ans+=(i*(sz[pos++]%mod))%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    gettimeofday(&endd, 0);
    int sec = endd.tv_sec - start.tv_sec;
    int usec = endd.tv_usec - start.tv_usec;
    printf("Total elapsed time: %.4f sec\n", sec+(usec / 1000000.0));
}