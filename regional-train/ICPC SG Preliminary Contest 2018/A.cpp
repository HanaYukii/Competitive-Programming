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
int n;
char b[105][105];
string tar = "ICPCASIASG";
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};
void dfs(int x,int y,int cur){
    if(cur==tar.size()){
        cout<<"YES"<<endl;
        exit(0);
    }
    f(8){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(min(nx,ny)<0)continue;
        if(max(nx,ny)>=n)continue;
        if(b[nx][ny]!=tar[cur])continue;
        dfs(nx,ny,cur+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    f(s.size()){
        int x = i / n;
        int y = i % n;
        b[x][y] = s[i];
    }
    f(n){
        fr(j,0,n){
            if(b[i][j]=='I')
                dfs(i,j,1);
        }
    }
    cout << "NO" << endl;
}
