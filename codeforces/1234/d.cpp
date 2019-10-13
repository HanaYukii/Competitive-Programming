#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7;
int v[400005][26];
int q[26];
string s;
void pushup(int x){
    f(26){
        v[x][i] = v[x<<1][i] | v[x<<1|1][i];
    }
}
void build(int x,int l,int r){
    if(l==r){
        v[x][s[l]-'a'] = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int pos,int vv){
    if(l==r){
        f(26){
            v[x][i] = 0;
        }
        v[x][vv] = 1;
        return ;
    }
    int mid = (l+r) >> 1;
    if(pos<=mid){
        update(x<<1,l,mid,pos,vv);
    }
    else{
        update(x<<1|1,mid+1,r,pos,vv);
    }
    pushup(x);
}
void query(int x,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        f(26){
            q[i] |= v[x][i];
        }
        return ;
    }
    int mid = (l+r) >> 1;
    if(ql<=mid){
        query(x<<1,l,mid,ql,qr);
    }
    if(qr>mid){
        query(x<<1|1,mid+1,r,ql,qr);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int qq;
    cin >> qq;
    int n = s.size();
    s = " " + s;
    build(1,1,n);
    while(qq--){
        int op;
        cin >> op;
        if(op==1){
            int pos;
            char c;
            cin >> pos >> c;
            int v = c-'a';
            update(1,1,n,pos,v);
        }
        else{
            int l,r;
            cin >> l >> r;
            f(26)q[i] = 0;
            query(1,1,n,l,r);
            int ans = 0;
            f(26){
                ans += q[i];
            }
            cout << ans << '\n';
        }
    }
}