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
//#define int long long
const int mod = 1e9 + 7;
map<int,int>v[10000];
int u[10000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n+5];
    f1(n){
        cin >> s[i];
        s[i] = " " + s[i];
    }
    f1(n){
        fr(j,1,n+1){
            if(s[i][j]=='?'){
                continue;
            }
            int x = s[i][j] - 'a';
            v[i][x]++;
            v[n+j][x]++;
        }
    }
    queue<pair<int,int> >q;
    f1(n*2){
        if(v[i].size() == 1){
            q.push({i,(*v[i].begin()).F});
            u[i] = 1;
        }
        else if(v[i].size() == 0){
            q.push({i,0});
            u[i] = 1;
        }
    }
    vector<pair<int,int > >ans;
    while(!q.empty()){
        pair<int,int>now = q.front();
        ans.pb(now);
        q.pop();
        int x = now.F;
        int y = now.S;
        //cout <<x<<' '<<y<<endl;
        if(x <= n){
            for(int i = n+1 ; i <= 2*n ; i++){
                if(u[i])continue;
                if(s[x][i-n]==('a'+y))
                    v[i][y]--;
                if(!v[i][y]){
                    v[i].erase(y);
                }
                if(v[i].size()==1){
                    q.push({i,(*v[i].begin()).F});
                    u[i] = 1;
                }
            }
        }
        else{
            for(int i = 1 ; i <= n ; i++){
                if(u[i])continue;
                if(s[i][x-n]==('a'+y))
                    v[i][y]--;
                if(!v[i][y]){
                    v[i].erase(y);
                }
                if(v[i].size()==1){
                    q.push({i,(*v[i].begin()).F});
                    u[i] = 1;
                }
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        int x = i.F;
        int y = i.S;
        //cout << x <<' '<<y<<endl;
        if(x<=n){
            cout <<'h' << ' ' << x <<' '<<(char)('a'+y)<<'\n';
        }
        else{
            cout <<'v' << ' '<< x-n <<' '<<(char)('a'+y)<<'\n';
        }
    }
}
