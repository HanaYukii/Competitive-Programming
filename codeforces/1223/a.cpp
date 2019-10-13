#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const ll mod =1e9+7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        if(k<=4){
            cout<<4-k<<endl;
        }
        else{
            if(k&1){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
}