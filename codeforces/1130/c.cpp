#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;
int d[5005];
int fi(int x){
    return d[x]==x?x:d[x]=fi(d[x]);
}
int main(){
	int x1,x2,y1,y2,n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>x1>>y1>>x2>>y2){
        x1--,x2--,y1--,y2--;
        string s[55];
        f(n*n)d[i]=i;
        f(n)cin>>s[i];
        f(n){
            fr(j,0,n){
                if(i>0){
                    if(s[i][j]==s[i-1][j]){
                        int x=fi(i*n+j);
                        int y=fi(i*n-n+j);
                        d[x]=y;
                    }
                }
                if(i<n-1){
                    if(s[i][j]==s[i+1][j]){
                        int x=fi(i*n+j);
                        int y=fi(i*n+n+j);
                        d[x]=y;
                    }
                }
                if(j>0){
                    if(s[i][j]==s[i][j-1]){
                        int x=fi(i*n+j);
                        int y=fi(i*n+j-1);
                        d[x]=y;
                    }
                }
                if(j<n-1){
                    if(s[i][j]==s[i][j+1]){
                        int x=fi(i*n+j);
                        int y=fi(i*n+j+1);
                        d[x]=y;
                    }
                }
            }
        }
        int st=fi(x1*n+y1);
        int ed=fi(x2*n+y2);
        if(st==ed){
            cout<<10<<endl;
        }
        else{
            vector<pair<int,int> >ff,ss;
            f(n){
                fr(j,0,n){
                    if(fi(i*n+j)==st){
                        ff.pb({i,j});
                    }
                    if(fi(i*n+j)==ed){
                        ss.pb({i,j});
                    }
                }
            }
            int Min=1e9;
            for(auto i:ff){
                for(auto j:ss){
                    Min=min((i.first-j.first)*(i.first-j.first)+(i.second-j.second)*(i.second-j.second),Min);
                }
            }
            cout<<Min<<endl;
        }
    }
}