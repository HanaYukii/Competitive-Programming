#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i))
#define ms1(i) memset(i,-1,sizeof(i))
#define F first
#define S second
string s[45];
string dp[45][100];
int from[45][100];
string build(string prev,string cur,int k){
    int left = k;
    if(k==0){
        if(cur>=prev){
            return cur;
        }
        else{
            return "";
        }
    }
    string tmp = cur;
    int i;
    for(i=0;i<(int)tmp.size()&&left;i++){
        if(tmp[i]!=prev[i]){
            tmp[i] = prev[i];
            left--;
        }
    }
    if(tmp>=prev){
        return tmp;
    }
    i--;
    int pos = -1;
    while(i>=0){
        if(prev[i]!='9'){
            pos = i;
            break;
        }
        i--;
    }
    if(pos==-1){
        return "";
    }
    left = k;
    tmp = cur;
    //cout<<prev<<' '<<cur<<' '<<k<<' '<<pos<<endl;
    for(int i=0;i<(int)tmp.size()&&left;i++){
        if(i<pos){
            if(tmp[i]==prev[i])continue;
            tmp[i] = prev[i];
            left--;
        }
        else if(i==pos){
            if(tmp[i]!=prev[i]+1){
                left--;
            }
            tmp[i] = prev[i] + 1;
        }
        else{
            if(tmp[i]!='0'){
                tmp[i] = '0';
                left--;
            }
        }
    }
    return tmp;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    f1(n){
        cin >> s[i];
    }
    f(m){
        dp[0][0] += "0";
    }
    f(n){
        fr(j,0,84){
            if(dp[i][j].size()==0)continue;
            for(int k=0;k<=m&&j+k<84;k++){
                string ss = build(dp[i][j],s[i+1],k);
                if(ss=="")continue;
                if(dp[i+1][j+k]==""||ss<dp[i+1][j+k]){
                    dp[i+1][j+k] = ss;
                    from[i+1][j+k] = j;
                }
            }
        }
    }
    vector<string>ans;
    for(int i=0;;i++){
        if(dp[n][i]!=""){
            int now = i;
            for(int j=n;j>=1;j--){
                ans.pb(dp[j][now]);
                now = from[j][now];
            }
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i<<endl;
    }
}
