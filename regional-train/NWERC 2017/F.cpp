#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
int l[maxn];
int r[maxn];
int val[maxn];
int pa[maxn];
int pos[maxn*10];
int D[maxn*10];
int f;
void solve(int pre,int L,int R){
   // cout << pre <<' '<<L<<' '<<R<<endl;
    if(f)return;
    if(L==R){
        pa[L] = pre;
        return;
    }
    int p1 = L,p2 = R;
    int t = R-L+1;
    int fi = 0;
    while(p1<=p2){
        if(l[p1]<L&&r[p1]>R){
            fi = p1;
            break;
        }
        if(l[p2]<L&&r[p2]>R){
            fi = p2;
            break;
        }
        p1++,p2--;
    }
    if(fi == 0){
       // cout<<"fail"<<endl;
        f = 1;
        return;
    }
    pa[fi] = pre;
    if(fi>L)
    solve(fi,L,fi-1);
    if(fi<R)
    solve(fi,fi+1,R);
}
int main(){
   // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    scanf("%d",&n);
    for(int i=2;i<=10000000;i++){
        if(D[i])continue;
        for(int j=i;j<=10000000;j+=i){
            D[j] = i;
        }
    }
    f1(n){
        scanf("%d",&val[i]);
        l[i] = 0;
        r[i] = n+1;
    }
    memset(pos,-1,sizeof(pos));
    for(int i=1;i<=n;i++){
        int tmp = val[i];
        while(tmp!=1){
            int j = D[tmp];
            if(~pos[j]){
                l[i] = max(l[i],pos[j]);
            }
            tmp /= j;
        }
        tmp = val[i];
        while(tmp!=1){
            int j = D[tmp];
            pos[j] = i;
            tmp /= j;
        }
    }
    memset(pos,-1,sizeof(pos));
    for(int i=n;i>=1;i--){
        int tmp = val[i];
        while(tmp!=1){
            int j = D[tmp];
            if(~pos[j]){
                r[i] = min(r[i],pos[j]);
            }
            tmp /= j;
        }
        tmp = val[i];
        while(tmp!=1){
            int j =D[tmp];
            pos[j] = i;
            tmp /= j;
        }
    }
    // cout << "here"<<endl;
    //cout << "here"<<endl;
    f = 0;
    solve(0,1,n);
    if(f){
        puts("impossible");
    }
    else{
        f1(n){
            printf("%d ",pa[i]);
        }
        puts("");
    }
}


