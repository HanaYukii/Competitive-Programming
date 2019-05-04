#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)

#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
#define pii pair<int,int>
ll cont[maxn],cont2[maxn];
struct node{
  ll mx;
}tree2[maxn<<2],tree[maxn<<2];

void pushup2(int now){
  tree2[now].mx=max(tree2[now<<1].mx,tree2[now<<1|1].mx);
}
void build2(int now,int l,int r){
  if(l==r){
    tree2[now].mx=cont2[l];
    return;
  }
  int mid=(l+r)/2;
  build2(now<<1,l,mid);
  build2(now<<1|1,mid+1,r);
  pushup2(now);
}
ll query2(int now,int l,int r,int L,int R){
  if(L<=l&&r<=R){
    return tree2[now].mx;
  }
  int mid=(l+r)>>1;
  ll ret=0;
  if(L<=mid){
    ret=max(query2(now<<1,l,mid,L,R),ret);
  }
  if(mid<R){
    ret=max(query2(now<<1|1,mid+1,r,L,R),ret);
  }
  return ret;
}

void pushup(int now){
  tree[now].mx=max(tree[now<<1].mx,tree[now<<1|1].mx);
}
void build(int now,int l,int r){
  if(l==r){
    tree[now].mx=cont[l];
    return;
  }
  int mid=(l+r)/2;
  build(now<<1,l,mid);
  build(now<<1|1,mid+1,r);
  pushup(now);
}
ll query(int now,int l,int r,int L,int R){
  if(L<=l&&r<=R){
    return tree[now].mx;
  }
  int mid=(l+r)>>1;
  ll ret=0;
  if(L<=mid){
    ret=max(query(now<<1,l,mid,L,R),ret);
  }
  if(mid<R){
    ret=max(query(now<<1|1,mid+1,r,L,R),ret);
  }
  return ret;
}
int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
        int n,g;
       	cin >> n >> g;
        f1(n){
          cin>>cont[i];
        }
        f1(n){
          cin>>cont2[i];
        }
        build(1,1,n);
        build2(1,1,n);
        int cnt=0;
        for(int i=1;i<=n;i++){
          for(int j=i;j<=n;j++){
            ll mx1=query(1,1,n,i,j),mx2=query2(1,1,n,i,j);
            //cout<<mx1<<' '<<mx2<<endl;
            if(abs(mx1-mx2)<=g){
              cnt++;
            }
          }
        }
       	printf("Case #%d: %d\n",c,cnt);
    }
    return 0;
}
