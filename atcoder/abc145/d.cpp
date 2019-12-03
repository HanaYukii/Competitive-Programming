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
    const int mod = 1e9+7;
    ll pm(int x){
        ll p = mod - 2;
        ll now = x;
        ll ret = 1;
        while(p){
            if(p&1){
                ret *= now;
                ret %= mod;
            }
            now *= now;
            now %= mod;
            p >>= 1;
        }
        return ret;
    }
    ll C(int x,int k){
        ll pre[x+5] = {};
        pre[0] = 1;
        f1(x){
            pre[i] = pre[i-1] * i % mod;
        }
        ll ret = pre[x] * pm(pre[k]) % mod * pm(pre[x-k]) % mod;
        return ret;
    }
    int main(){
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
        int x, y;
        cin >> x >> y;
        int tx = -1 , ty = -1;
        f(x/2+1){
            int lx = x - i * 2;
            int ly = y - i;
            if(ly == lx * 2){
                tx = i;
                ty = lx;
                break;
            }
        }
        if(tx == -1){
            cout << 0 << endl;
            exit(0);
        }
        cout << C(tx+ty,tx) << endl;
    }
