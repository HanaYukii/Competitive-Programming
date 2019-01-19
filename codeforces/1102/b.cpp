
 #include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
set<int>ins[5005];
int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    while(cin>>n>>m){
        vector<int>ans;
        f(n){
            cin>>cont[i];
        }
        for(int i=0;i<m;i++){
            ans.pb(i+1);
            ins[cont[i]].insert(i+1);
        }
        for(int i=m;i<n;i++){
            int now=cont[i];
            int f=0;
                for(int j=1;j<=m;j++){
                    if(ins[now].find(j)==ins[now].end()){
                        ans.pb(j);
                        ins[now].insert(j);
                        f=1;
                        break;
                    }
                }
            if(!f){
                cout<<"NO"<<endl;
                exit(0);
            }
        }
        cout<<"YES"<<endl;
        for(auto i:ans){
            cout<<i<<' ';
        }
        cout<<endl;
    }
}


