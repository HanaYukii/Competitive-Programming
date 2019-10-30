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
const int mod = 1e9;
struct m{
    ll num[256][256];
    int n;
};
m mul(m b,m a){
    m ret;
    ret.n = a.n;
    ms(ret.num);
    f(a.n){
        fr(j,0,a.n){
            fr(k,0,a.n){
                ret.num[i][j]+=a.num[i][k]*b.num[k][j];
                ret.num[i][j]%= mod;
            }
        }
    }
    return ret;
}
void solve(m a,ll k){
    m ret,now=a;
    ret.n=a.n;
    ms(ret.num);
    f(a.n){
        ret.num[i][i] = 1;
    }
    while(k){
        if(k&1){
            ret = mul(ret,now);
        }
        now = mul(now,now);
        k >>= 1;
    }
    cout<<ret.num[0][0]<<endl;;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    m mat;
    int f[10];
    f[0]=f[1]=1;
    mat.n=(1<<n);
    ms(mat.num);
    fr(i,2,10){
        f[i]=f[i-1]+f[i-2];
    }
    f(1<<n){
        fr(j,0,1<<n){
            if(i&j)continue;
            int tar = i|j;
            ll ret = 1;
            int cur = 0;
            for(int k=0;k<n;k++){
                if(tar&(1<<k)){
                    ret *= f[cur];
                    ret %= mod;
                    cur = 0;
                }
                else{
                    cur++;
                }
            }
            ret *= f[cur];
            ret %= mod;
            mat.num[i][j]=ret;
        }
    }
    solve(mat,k);
}
