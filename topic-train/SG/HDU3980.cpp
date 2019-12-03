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
const int mod = 1e9 + 7;
int n, k;
int sg[1005];
int solve(int x){
    if(~sg[x]){
        return sg[x];
    }
    if(x < k){
        return sg[x] = 0;
    }
    set<int>st;
    for(int i = 0 ; i <= x - k ; i++){
        st.insert(solve(i)^solve(x-k-i));
    }
    int cur = 0;
    while(st.count(cur))cur++;
    return sg[x] = cur;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int c = 0;
    while(t--){
        memset(sg,-1,sizeof(sg));
        c++;
        cin >> n >> k;
        if(k > n){
            printf("Case #%d: abcdxyzk\n",c);
        }
        else{
            int x = solve(n-k);
            if(x){
                printf("Case #%d: abcdxyzk\n",c);
            }
            else{
                printf("Case #%d: aekdycoin\n",c);

            }
        }
    }
}
