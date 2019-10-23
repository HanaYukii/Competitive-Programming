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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int,int> >v;
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    int ans[s+5]={};
    for(int i=0;i<s;i++){
        int add;
        cin >> add;
        v.pb({add,i});
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    for(int i=0;i<s;i++){
        if(!n){
            cnt += v[i].F;
        }
        else{
            int cur = min(n,d-v[i].F);
            n -= cur;
            ans[v[i].S]=cur;
        }
    }
    if(cnt<m){
        cout<<"impossible"<<endl;
    }
    else{
        f(s){
            cout<<ans[i]<<' ';
        }
        cout << endl;
    }
    return 0;
}
