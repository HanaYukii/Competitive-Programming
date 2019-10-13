#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
int main(){
	int n,m;
    while(cin>>n>>m){
    	vector<ll>v;
        ll sum = 0;
        f(n){
            int add;
            cin >> add;
            v.pb(add);
            sum += add;
        }
        if(sum<m){
            cout<<-1<<endl;
            exit(0);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int mi = 0;
        for(int i=1<<20;i;i>>=1){
            int now = n - mi - i;
            if(now<=0){
                continue;
            }
            ll cur = 0;
            int mis = -1;
            for(int j=0;j<n;j++){
                if(j%now==0){
                    mis++;
                }
                cur += max(v[j]-mis,0LL);
            }
            if(cur>=m){
                mi += i;
            }
        }
        cout << n - mi << endl;
    }
}