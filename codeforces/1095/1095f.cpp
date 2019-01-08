#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll c[maxn];
struct e{
    int x,y;
    ll w;
}cont[maxn];
bool cmp(e x,e y){
    return x.w<y.w;
}
int d[maxn];
int find(int x){
    return d[x]==x?d[x]:d[x]=find(d[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m;
    int Min=0;
    c[0]=1e18;
    f1(n){
        cin>>c[i];
        if(c[i]<c[Min]){
            Min=i;
        }
    }

    for(int i=0;i<m;i++){
        cin>>cont[i].x>>cont[i].y>>cont[i].w;
    }
    int now=m;
    for(int i=1;i<=n;i++){
        if(i!=Min){
        cont[now].x=Min;
        cont[now].y=i;
        cont[now++].w=c[Min]+c[i];
    }
    }
    sort(cont,cont+m+n-1,cmp);
    for(int i=1;i<=n;i++){
        d[i]=i;
    }
    int cnt=0;
    ll sum=0;
    for(int i=0;i<n+m-1;i++){
        int x=find(cont[i].x),y=find(cont[i].y);
        if(x!=y){
            d[x]=y;
            sum+=cont[i].w;
            
        }
    }
    cout<<sum<<endl;
}