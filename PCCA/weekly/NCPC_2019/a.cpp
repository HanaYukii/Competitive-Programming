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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    char nxt = s.back();
    int n;
    cin >> n;
    int cnt[26]={};
    vector<string>v;
    int val = 0;
    int ans = 0;
    string va="";
    string an="";
    f(n){
        string add;
        cin >> add;
        v.pb(add);
        cnt[add[0]-'a']++;
        if(add[0]==nxt&&val==0){
            val = 1;
            va = add;
        }
    }
    for(auto i:v){
        if(i[0]!=nxt)continue;
        if(i[0]==i.back()&&cnt[i[0]-'a']==1&&ans==0){
            ans = 1;
            an = i;
        }
        else if(cnt[i.back()-'a']==0&&ans==0){
            ans = 1;
            an = i;
        }
    }
    if(!val){
        cout<<'?'<<endl;
    }
    else if(!ans){
        cout<<va<<endl;
    }
    else{
        cout<<an<<'!'<<endl;
    }
}
