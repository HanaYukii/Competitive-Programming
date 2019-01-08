#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

struct w{
    char c;
    int t;
}cont[205];
int main(){
    ios_base::sync_with_stdio(0);
    string s;
    int k;
    while(cin>>s>>k){
        int cnt=0;
        int f=0;
        int tc=0;
        for(int i=0;i<(int)s.size();i++){
            if(i==(int)s.size()-1){
                cont[cnt].c=s[i];
                cont[cnt++].t=0;
            }
            else if(s[i+1]=='?'){
                cont[cnt].c=s[i];
                cont[cnt++].t=1;
                tc++;
                i++;
            }
            else if(s[i+1]=='*'){
                cont[cnt].c=s[i];
                cont[cnt++].t=2;
                tc++;
                f=1;
                i++;
            }
            else{
                cont[cnt].c=s[i];
                cont[cnt++].t=0;
            }
        }
        //cout<<cnt<<' '<<k<<' '<<f<<' '<<tc<<endl;
        if(cnt<k&&!f){
            cout<<"Impossible"<<endl;
        }
        else if(cnt>k&&cnt-k>tc){
            cout<<"Impossible"<<endl;
        }
        else{
            int now=cnt;
            for(int i=0;i<cnt;i++){
                if(cont[i].t==0){
                    cout<<cont[i].c;
                }
                else if(cont[i].t==1){
                    if(now>k){
                        now--;
                    }
                    else{
                        cout<<cont[i].c;
                    }
                }
                else{
                    if(now<k){
                        for(int j=now;j<=k;j++){
                            cout<<cont[i].c;
                        }
                        now=k;
                    }
                    else if(now>k){
                        now--;
                    }
                    else{
                        cout<<cont[i].c;
                    }
                }
            }
        }
        cout<<endl;
    }
    
}