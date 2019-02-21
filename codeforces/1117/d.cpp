#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back

const int mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll n,m;
    while(cin>>n>>m){
        ll mat[65][105][105]={};
        if(n<m){
            cout<<1<<endl;
            exit(0);        
        }
        mat[0][0][0]=1;
        mat[0][0][m-1]=1;
        f1(m-1){
            mat[0][i][i-1]=1;
        }
        /*f(m){
            fr(j,0,m){
                cout<<mat[0][i][j]<<' ';
            }
            cout<<endl;
        }*/
        f1(63){
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    for(int l=0;l<m;l++){
                        mat[i][j][k]+=mat[i-1][l][k]*mat[i-1][j][l];
                        mat[i][j][k]%=mod;
                    }
                    //cout<<mat[i][j][k]<<endl;
                }
            }
        }
        int now=0;
        ll ff[m]={};
        f(m){
            ff[i]=1;
        }
        ff[0]=2;
        n-=m;
        while(n){
            if(n&1){
                //cout<<now<<endl;
                ll tmp[m]={};
                f(m){
                    fr(j,0,m){
                        tmp[i]+=ff[j]*mat[now][i][j];
                        tmp[i]%=mod;
                    }
                }
                f(m){
                    ff[i]=tmp[i];
                }
            }
            n>>=1;
            now++;
        }
        cout<<ff[0]<<'\n';
    
    }
}