#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
ll pre[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    while(cin>>s){
        n=s.size();
        s=" "+s;
        
        vector<int>bp;
        bp.pb(0);
        f1(n){
            if(s[i]=='b'){
                bp.pb(i);
            }
        }
        //ll ans=0;
        f1(n){
            pre[i]=pre[i-1];
            if(s[i]=='a'){
                int x=*(lower_bound(bp.begin(),bp.end(),i)-1);
                if(x==0){
                    pre[i]++;
                }
                else{
                    pre[i]+=pre[x]+1;
                    pre[i]%=mod;
                }
            }
            pre[i]%=mod;
            //cout<<i<<' '<<pre[i]<<endl;
        }
        cout<<pre[n]<<endl;
    }
    

}