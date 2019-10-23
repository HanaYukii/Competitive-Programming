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
#define F first
#define S second
bool nl[maxn];
int pa[maxn];
ll ans[maxn];
vector<int>g1[maxn],g2[maxn];
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pa[0]=-1;
    for(int i=1;i<n;i++){
        cin >> pa[i];
        pa[i]--;
        g1[pa[i]].pb(i);
        nl[pa[i]]=1;
    }
    f(n){
        cin >> ans[i];
        if(!ans[i])ans[i]--;
    }
    f(n){
        if(ans[i]==-1&&nl[i]){
            for(auto j:g1[i]){
                pa[j] = pa[i];
            }
            pa[i]=-2;
        }
    }
    f(n){
        if(pa[i]>=0){
            g2[pa[i]].pb(i);
        }
    }
    f(n){
        if(pa[i]!=-2 && nl[i]){
            vector<int>tar;
            ll sum = 0;
            for(auto j:g2[i]){
                if(ans[j]==-1){
                    tar.pb(j);
                }
                else{
                    sum += ans[j];
                }
            }
            if(sum+tar.size()==ans[i]){
                for(auto j:tar){
                    ans[j] = 1;
                }
            }
            else if(tar.size()==1){
                ans[tar[0]]=ans[i]-sum;
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        if(!nl[i])continue;
        if(ans[i]!=-1)continue;
        ll sum = 0;
        for(auto j:g1[i]){
            sum += ans[j];
        }
        ans[i] = sum;
    }
    int gg = 0;
    f(n){
        if(ans[i]<1)gg = 1;
        ll sum = 0;
        for(auto j:g1[i]){
            sum += ans[j];
        }
        if(sum !=ans[i]&&nl[i]){
            gg = 1;
        }
    }
    if(gg){
        cout<<"impossible"<<endl;
    }
    else{
        f(n){
            cout<<ans[i]<<'\n';
        }
    }
}
