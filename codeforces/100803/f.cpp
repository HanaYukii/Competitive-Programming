
 #include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
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
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>cont[i].x>>cont[i].y>>cont[i].w;
    }

    sort(cont,cont+m,cmp);
    vector<int>mst;
    for(int i=1;i<=n;i++){
        d[i]=i;
    }
    ll sum=0;
    for(int i=0;i<m;i++){
        int x=find(cont[i].x),y=find(cont[i].y);
        if(x!=y){
            mst.pb(i);
            d[x]=y;
            sum+=cont[i].w;
        }
    }
    int cnt=0;
    int wsum=0;
    for(int i=0;i<mst.size();i++){
        for(int j=1;j<=n;j++){
            d[j]=j;
        }
        int jo=0;
        int tsum=0;
        for(int j=0;j<m;j++){
            if(j==mst[i])
                continue;
            int x=find(cont[j].x),y=find(cont[j].y);
            if(x!=y){
                jo++;
                d[x]=y;
                tsum+=cont[j].w;
            }
        }
        if(tsum!=sum||jo!=mst.size()){
            cnt++;
            wsum+=cont[mst[i]].w;
        }
    }
    cout<<cnt<<' '<<wsum<<endl;
}