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
#define bg begin()
#define ed end()
#define pii pair<int,int>

int main()
{
    int t;
	  cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
        int n,q;
       	cin >> n ;
        int k[505][505] = {};
        int p[505]={0};
        int ok[505]={};
        f(n){
            string s;
            cin >>s;
            for(int j=0;j<s.size();j++){
                if(s[j]=='S'){
                    k[i][j]=1;
                }
                else if(s[j]=='R'){
                    k[i][j]=2;
                }
                else{
                    k[i][j]=3;
                }
            }
        }
        int f=0;
        string ans="";
        while(1){
            int rem=0;
            int ex[4]={};
            f(n){
                if(ok[i])continue;
                rem=1;
                ex[k[i][p[i]]]=1;
                //cout<<k[i][p[i]]<<' ';  
            }
          //cout<<ex[1]<<' '<<ex[2]<<' '<<ex[3]<<endl;
          //system("PAUSE");
          if(!rem)break;
          if(ex[1]&&ex[2]&&ex[3]){
            f=1;
            break;
          }
          else if(ex[1]&&ex[2]){
              ans+="R";
          }
          else if(ex[2]&&ex[3]){
              ans+="P";
          }
          else if(ex[1]&&ex[3]){
              ans+="S";
          }
          else if(ex[1]){
              ans+="R";
          }
          else if(ex[2]){
              ans+="P";
          }
          else{
            ans+="S";
          }
          //cout<<ans<<endl;
          int last;
          if(ans[ans.size()-1]=='S'){
            last=3;
          }
          else if(ans[ans.size()-1]=='R'){
            last=1;
          }
          else{
            last=2;
          }
          f(n){
            if(ok[i])continue;
            if(k[i][p[i]]==last){
              ok[i]=1;
            }
            p[i]++;
            if(k[i][p[i]]==0){
              p[i]=0;
            }
          }
        }
       	printf("Case #%d: ",c);
        if(f){
          cout<<"IMPOSSIBLE"<<endl;
        }
        else
        cout<<ans<<endl;
       	
    }
    return 0;
}
