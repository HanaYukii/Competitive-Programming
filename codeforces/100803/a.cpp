#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
    ios_base::sync_with_stdio(0);
    string s;
    int n,m;
    while(cin>>n>>m){
        int c[20]={};
        int cont[20]={};
        int z[20]={};
        f(n){
            cin>>z[i];
            cont[i]=z[i];
        }
        f(m){
            cin>>c[i];
        }
        int b=0;
        int sum=0;
        int ans=1e9;
        int flag=0;
        int now=1;
        f(m){
            fr(j,0,c[i]){
                int f=0;
                for(int k=b;k<n;k++){
                    if(cont[k]==now){
                        f=1;
                        //cout<<k<<' '<<b<<endl;
                        for(int l=k;l>b;l--){
                            swap(cont[l],cont[l-1]);
                            sum++;
                        }
                        b++;
                        break;
                    }
                    
                }
                if(!f){
                        flag=1;
                        goto second;
                }
            }
            now^=1;
        }
        
        ans=min(ans,sum);
        
        second:;
        //cout<<"gg"<<endl;
        f(n){
            cont[i]=z[i];
        }
        now=0;
        flag=0;
        sum=0;
        b=0;
        f(m){
            fr(j,0,c[i]){
                int f=0;
                for(int k=b;k<n;k++){
                    if(cont[k]==now){
                        f=1;
                        for(int l=k;l>b;l--){
                            swap(cont[l],cont[l-1]);
                            sum++;
                        }
                        b++;
                        break;
                    }
                    
                }
                if(!f){
                    flag=1;
                        //goto second;
                }
            }
            now^=1;
        }
        if(!flag){
            ans=min(ans,sum);
        }
        cout<<ans<<endl;
    }
    
}