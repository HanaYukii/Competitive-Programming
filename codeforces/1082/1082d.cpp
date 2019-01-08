#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    int n;
    cin>>n;
    int sum=0;
    vector<int>one;
    vector<int>two;
    for(int i=1;i<=n;i++){
        cin>>cont[i];
        sum+=cont[i];
        if(cont[i]==1){
            one.pb(i);
        }
        else{
            two.pb(i);
        }
    }
    if(sum<(n-1)*2){
        cout<<"NO"<<endl;
        exit(0);
    }

    int ans=two.size()+min(2,(int)one.size())-1;
    cout<<"YES"<<' '<<ans<<endl;
    cout<<n-1<<endl;
    if(one.size()>=2){
        cout<<one[0]<<' '<<two[0]<<endl;
        for(int i=1;i<two.size();i++){
            cout<<two[i-1]<<' '<<two[i]<<endl;
        }
        cout<<two[two.size()-1]<<' '<<one[1]<<endl;;
        for(int i=0;i<two.size();i++){
            cont[two[i]]-=2;
        }
        int now=0;
        for(int i=2;i<one.size();i++){
            while(cont[two[now]]==0){
                now++;
            }
            cout<<two[now]<<' '<<one[i]<<endl;
            cont[two[now]]--;
        }
    }
    else if(one.size()==1){
        cout<<one[0]<<' '<<two[0]<<endl;
        for(int i=1;i<two.size();i++){
            cout<<two[i-1]<<' '<<two[i]<<endl;
        }
    }
    else{
        for(int i=1;i<two.size();i++){
            cout<<two[i-1]<<' '<<two[i]<<endl;
        }
    }
}