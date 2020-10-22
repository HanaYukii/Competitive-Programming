#include<iostream>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
ll add[maxn<<2];
ll mi[maxn<<2];
ll mx[maxn<<2];
ll amx,ami;
void pushdown(int x){
	if(add[x]){
		add[x<<1] += add[x];
		add[x<<1|1] += add[x];
		mi[x<<1] += add[x];
		mi[x<<1|1] += add[x];
		mx[x<<1] += add[x];
		mx[x<<1|1] += add[x];
		add[x] = 0;
	}
	mi[x<<1] = max(mi[x<<1],mi[x]);
	mi[x<<1] = min(mi[x<<1],mx[x]);
	mx[x<<1] = max(mx[x<<1],mi[x]);
	mx[x<<1] = min(mx[x<<1],mx[x]);
	mi[x<<1|1] = max(mi[x<<1|1],mi[x]);
	mi[x<<1|1] = min(mi[x<<1|1],mx[x]);
	mx[x<<1|1] = max(mx[x<<1|1],mi[x]);
	mx[x<<1|1] = min(mx[x<<1|1],mx[x]);
}
void pushup(int x){
    mx[x] = max(mx[x<<1],mx[x<<1|1]);
    mi[x] = min(mi[x<<1],mi[x<<1|1]);
}
void build(int x,int l,int r){
    if(l==r){
        cin >> mi[x];
        mx[x] = mi[x];
        return;
    }
    int mid = (l+r) >> 1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int ql,int qr,ll v,int op){
    if(l==ql&&r==qr){
        if(op==1){
        	add[x] += v;
        	mi[x] += v;
        	mx[x] += v;
        }
        else if(op==2){
        	mx[x] = min(mx[x],v);
        	mi[x] = min(mi[x],v);
        }
        else{
        	mx[x] = max(mx[x],v);
        	mi[x] = max(mi[x],v);
        }
        return;
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(qr<=mid){
        update(x<<1,l,mid,ql,qr,v,op);
    }
    else if(ql>mid){
        update(x<<1|1,mid+1,r,ql,qr,v,op);
    }
    else{
        update(x<<1,l,mid,ql,mid,v,op);
        update(x<<1|1,mid+1,r,mid+1,qr,v,op);
    }
    pushup(x);
}
void query(int x,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
    	amx = max(amx,mx[x]);
    	ami = min(ami,mi[x]);
    	return ;    
    }
    pushdown(x);
    int mid = (l+r) >> 1;
    if(qr<=mid){
        query(x<<1,l,mid,ql,qr);
    }
    else if(ql>mid){
        query(x<<1|1,mid+1,r,ql,qr);
    }
    else{
        query(x<<1,l,mid,ql,mid);
        query(x<<1|1,mid+1,r,mid+1,qr);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    build(1,1,n);
    while(k--){
        int op,l,r;
        cin >> op >> l >> r;
        if(op==4){
        	ami = 2e9;
        	amx = -2e9;
        	query(1,1,n,l,r);
        	cout << ami << ' ' << amx << '\n';
        }
        else{
        	int v;
        	cin >> v;
        	update(1,1,n,l,r,v,op);
        }
    }
}