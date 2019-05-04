#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
int Min,n;//=1e6;
set<pair<int,int> >st;
void dfs(int now,int xa,int ya){
   // cout<<now<<' '<<xa<<' '<<ya<<endl;
    if(now==n){
        if(xa&&ya)
        Min=min(Min,abs(xa-ya));
        return;
    }
    else{
        pair<int,int>add;
        add.first=(int)abs(xa-ya);
        add.second=now;
        if(st.find(add)!=st.end())
            return;
        else{
            st.insert(add);
        }
        dfs(now+1,xa+cont[now],ya);
        dfs(now+1,xa,ya+cont[now]);
        dfs(now+1,xa,ya);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    //int n;
    while(cin>>n){
        st.clear();
        Min=1e6;
        f(n){
            cin>>cont[i];
        }
        if(n>18){
            cout<<0<<endl;
            exit(0);
        }
	    else{
            dfs(0,0,0);
            cout<<Min<<endl;
        }
    }
}