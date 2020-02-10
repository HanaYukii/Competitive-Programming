#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9 + 7;
int v[105];
int dp[105][105][105][2];
int solve(int cur,int lo,int le,int last){
  if(~dp[cur][lo][le][last]){
    return dp[cur][lo][le][last];
  }
  if(cur == 0){
    return 0;
  }
    if(v[cur]){
      return dp[cur][lo][le][last] = solve(cur-1,lo,le,v[cur]%2) + (v[cur] % 2 != last);
    }
    else if(!lo){
        return dp[cur][lo][le][last] = solve(cur-1,lo,le-1,0) + (last == 1);
    }
    else if(!le){
      return dp[cur][lo][le][last] = solve(cur-1,lo-1,le,1) + (last == 0);
    }
    else{
        return dp[cur][lo][le][last] = min(solve(cur-1,lo-1,le,1)+(last == 0),solve(cur-1,lo,le-1,0)+(last == 1));
    }
  }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        int lo = n / 2 + n % 2;
        int le = n / 2;
        for(int i = 1 ; i <= n ; i++){
          cin >> v[i];
          if(v[i]){
            if(v[i]&1){
              lo--;
            }
            else{
              le--;
            }
          }
        }
        ms1(dp);
        cout << min(solve(n,lo,le,1),solve(n,lo,le,0))<< '\n';
    }
    
    
}
