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
    int n;
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        if(k==1){
            cout<<"NO"<<endl;
        }
        else if(k==2&&s[0]>=s[1]){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<s[0]<<' '<<s.substr(1,k-1)<<endl;
        }
    }

}