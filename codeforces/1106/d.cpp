#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
vector<int>g[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        set<int>st;
        f(m){
            int add1,add2;
            cin>>add1>>add2;
            g[add1].pb(add2);
            g[add2].pb(add1);
        }
        st.insert(1);
        int v[n+5]={0};
        v[1]=1;
        while(!st.empty()){
            int x=*(st.begin());
            st.erase(x);
            for(auto i:g[x]){
                if(!v[i]){
                    v[i]=1;
                    st.insert(i);
                }
            }
            cout<<x<<' ';
        }
        cout<<endl;
    }
    

}