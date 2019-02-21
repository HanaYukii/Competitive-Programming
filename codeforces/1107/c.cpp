#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;


int main(void){
    ios_base::sync_with_stdio(false);
    ll n,k,t;
    
    while(cin>>n>>k){
        ll cont[200005]={};
        vector<int>now;
        f(n){
            cin>>cont[i];
        }
        string s;
        cin>>s;
        ll ans=0;
        int cnt=1;
        now.pb(cont[0]);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                now.pb(cont[i]);
                cnt++;
            }
            else{
                if(cnt<=k){
                    for(ll i:now){
                        ans+=i;
                    }
                }
                else{
                    sort(now.begin(),now.end());
                    reverse(now.begin(),now.end());
                    fr(j,0,k){
                        ans+=now[j];
                    }
                }
                now.clear();
                now.pb(cont[i]);
                cnt=1;
            }
        }
        if(cnt<=k){
                for(ll i:now){
                        ans+=i;
                }
            }
            else{
                sort(now.begin(),now.end());
                reverse(now.begin(),now.end());
                fr(j,0,k){
                                        ans+=now[j];
                    }
            }
        cout<<ans<<endl;
    }

}