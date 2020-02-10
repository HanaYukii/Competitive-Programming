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
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        map<int,int>mp;
        int n;
        cin >> n;
        for(int i = 2 ; i <= sqrt(n) ; i++){
            if(n % i)continue;
            while(n % i == 0){
                mp[i]++;
                n /= i;
            }
        }
        if(n > 1){
            mp[n]++;
        }
        if(mp.size() >= 3){
            int ans1 = 1, ans2 = 1, ans3 = 1;
            for(auto i:mp){
                if(ans1 == 1){
                    while(i.S--){
                        ans1 *= i.F;
                    }
                }
                else if(ans2==1){
                    while(i.S--){
                        ans2 *= i.F;
                    }
                }
                else{
                    while(i.S--){
                        ans3 *= i.F;
                    }
                }
            }
            cout << "YES\n";
            cout << ans1 <<' '<<ans2 <<' '<<ans3 <<'\n';
        }
        else if(mp.size() == 1){
            for(auto i:mp){
                if(i.S >= 6){
                    int cur = i.F;
                    cout << "YES\n";
                    cout << cur << ' ' << cur * cur <<' ';
                    int left = i.S - 4;
                    while(left --){
                        cur *= i.F;
                    }
                    cout << cur << '\n';
                }
                else{
                    cout << "NO\n";
                }
            }
        }
        else{
            int ans1 = 1, ans2 = 1, ans3 = 1;
            for(auto i:mp){
                int cnt = i.S - 1;
                if(ans1 == 1){
                    ans1 *= i.F;
                }
                else{
                    ans2 *= i.F;
                }
                while(cnt--){
                    ans3 *= i.F;
                }
            }
            if(min({ans1,ans2,ans3})!=1&&ans1 != ans2 && ans2 != ans3 && ans3 !=ans1){
                cout << "YES\n";
                cout << ans1 <<' '<<ans2 <<' '<<ans3<<'\n';
            }
            else{
                cout << "NO\n";
            }
        }
    }
}
