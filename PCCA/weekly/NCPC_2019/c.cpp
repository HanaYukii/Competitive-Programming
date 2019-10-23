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
	int n;
    cin >> n;
    vector<int>v;
    f(n){
        int add;
        cin >> add;
        v.pb(add);
    }
    int mi = 1e9;
    int idx = 0;
    for(int i=0;i+2<n;i++){
        int cur = max(v[i],v[i+2]);
        if(cur<mi){
            mi = cur;
            idx = i+1;
        }
    }
    cout << idx <<' '<<mi<<endl;
}
