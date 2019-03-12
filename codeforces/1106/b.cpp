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

struct s{
    ll cost;
    int idx;
    bool operator<(const s &x)const{
        if(x.cost!=cost){
            return x.cost>cost;
        }
        else{
            return x.idx>idx;
        }
    }
} cont[100005];

int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        ll num[n+5]={};
        set<s>st;
        f1(n)cin>>num[i];
        f1(n){
            cin>>cont[i].cost;
            cont[i].idx=i;
            st.insert(cont[i]);
        }
        while(m--){
            ll x,y,ans=0;
            cin>>x>>y;
            if(num[x]){
                if(num[x]>y){
                    num[x]-=y;
                    cout<<cont[x].cost*y<<endl;
                    continue;
                }
                else{
                    y-=num[x];
                    ans+=num[x]*cont[x].cost;
                    num[x]=0;
                    st.erase(cont[x]);
                }
            }
            //cout<<ans<<endl;
            
            while(y){
                if(st.empty()){
                    cout<<0<<endl;
                    goto endd;
                }
                x=st.begin()->idx;
                if(num[x]>y){
                    num[x]-=y;
                    ans+=cont[x].cost*y;
                    y=0;
                }
                else{
                    y-=num[x];
                    ans+=num[x]*cont[x].cost;
                    num[x]=0;
                    st.erase(cont[x]);
                }
                //cout<<ans<<endl;
            }
            cout<<ans<<endl;
            endd:;
        }
    }
    

}