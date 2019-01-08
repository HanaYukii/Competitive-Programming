#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
vector<int>g[maxn];

int main(){
    int n;
    ios_base::sync_with_stdio(0);
    cin>>n;
    vector<int>one;
    f(n){
        int add1,add2;
            
        cin>>add1>>add2;
        if(i==0){
            one.pb(add1);
            one.pb(add2);
        }
        g[add1].pb(add2);
        g[add2].pb(add1);
    }
    vector<int>ans;


        if(g[1][0]==one[0]||g[1][0]==one[1]){
        ans.pb(1);
        ans.pb(g[1][0]);
        for(int i=0;i<n-2;i++){
            int now=ans[i+1];
            int pre=ans[i];
            if(g[now][0]==pre){
                ans.pb(g[now][1]);
            }
            else{
                ans.pb(g[now][0]);
            }
        }
            
            for(auto i:ans){
                cout<<i<<' ';
            }
            cout<<endl;
            
        }
        else{
            ans.clear();
            ans.pb(1);
            ans.pb(g[1][1]);
            for(int i=0;i<n-2;i++){
                int now=ans[i+1];
                int pre=ans[i];
                if(g[now][0]==pre){
                    ans.pb(g[now][1]);
                }
                else{
                    ans.pb(g[now][0]);
                }
            }
            for(auto i:ans){
                cout<<i<<' ';
            }
            cout<<endl;
        }
    
    
}