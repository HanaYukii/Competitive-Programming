#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
int main(){
    long long n,k,m;
    while(cin>>n>>k>>m){
        ll cont[n+5]={};
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>cont[i];
            sum+=cont[i];
        }
        sort(cont,cont+n);
        double Max=(double)(sum+min(m,n*k))/n;
        for(long long i=0;i<min(n-1,m);i++){
            //cout<<"gg"<<endl;
            /*if((n-i-1)*k<m-1-i){
                break;
            }*/
            sum-=cont[i];
            Max=max(Max,double((sum+(min(m-i-1,(n-i-1)*k)))/(double)(n-i-1)));
        }
        cout<<fixed<<setprecision(15)<<Max<<endl;
    }
}