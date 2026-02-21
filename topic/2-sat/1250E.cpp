#include<bits/stdc++.h>

#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
using namespace std;
int d[200];
int fi(int x){
    return d[x] == x ? x :d[x] = fi(d[x]);
}
int sz[200];
int yes[200];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin >> t;
	while(t--){
	    int n,m,k;
        cin >> n >> m >> k;
        string s[n+5],rev[n+5];
        f(n){
            cin >> s[i];
            rev[i] = s[i];
            reverse(rev[i].begin(),rev[i].end());
        }
        f(2*n){
            d[i] = i;
            sz[i] = 0;
            yes[i] = 0;
        }
        int f = 0;
        f(n){
            fr(j,i+1,n){
                int ok1 = 0,ok2 = 0;
                int cnt = 0,cnt2=0;
                fr(l,0,m){
                    if(s[i][l]==s[j][l])
                        cnt++;
                    if(s[i][l]==rev[j][l])
                        cnt2++;
                }
                if(cnt>=k)ok1 = 1;
                if(cnt2>=k)ok2 = 1;
                if(!ok1&&!ok2){
                    f = 1;
                }
                if(ok1&&ok2)continue;
                if(ok1&&!ok2){
                    int x = fi(i);
                    int y = fi(j);
                    d[x] = y;
                    x = fi(i+n);
                    y = fi(j+n);
                    d[x] = y;
                }
                else{
                    int x = fi(i);
                    int y = fi(j+n);
                    d[x] = y;
                    x = fi(i+n);
                    y = fi(j);
                    d[x] = y;
                }
            }
        }
        f(n){
            if(fi(i)==fi(i+n)){
                f = 1;
            }
        }
        if(f){
            cout<<-1<<endl;
        }
        else{
            f(n){
                yes[fi(i)]++;
                sz[fi(i)]++;
            }
            fr(i,n,2*n){
                //cout << fi(i)<<' ';
                sz[fi(i)]++;
            }
            set<int>c;
            f(2*n){
                if(!sz[i])continue;
                if(yes[i]*2<sz[i])continue;
                //cout<<i<<' '<<yes[i]<<' '<<sz[i]<<endl;
                c.insert(i);
            }
            f(n){
                if(c.count(fi(i))&&c.count(fi(i+n))){
                    c.erase(fi(i+n));
                }
            }
            vector<int>ans;
            fr(i,n,2*n){
                if(c.count(fi(i))){
                    ans.pb(i-n+1);
                }
            }
            cout << ans.size() << endl;
            for(auto i:ans){
                cout<<i<<' ';
            }
            cout << endl;
        }
    }
}
