#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int cont[5205][5205];
int swc(char x){
    if(x<='9'&&x>='0')
        return x-'0';
    else
        return (x-'A')+10;
}
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<n/4;j++){
                int num=swc(s[j]);
                cont[i][j*4]=((num&8)>0);
                cont[i][j*4+1]=((num&4)>0);
                cont[i][j*4+2]=((num&2)>0);
                cont[i][j*4+3]=((num&1)>0);
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            int now=1;
            for(int j=1;j<n;j++){
                if(cont[i][j]==cont[i][j-1]){
                    now++;
                }
                else{
                    ans=__gcd(ans,now);
                    now=1;
                }
            }
            ans=__gcd(ans,now);
        }
        for(int i=0;i<n;i++){
            int now=1;
            for(int j=1;j<n;j++){
                if(cont[j][i]==cont[j-1][i]){
                    now++;
                }
                else{
                    ans=__gcd(ans,now);
                    now=1;
                }
            }
            ans=__gcd(ans,now);
        }
        cout<<ans<<endl;
    }
}