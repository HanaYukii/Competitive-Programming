#include<bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
int len[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
void pushup(int x,int llen,int rlen){
	len[x] = max(len[x<<1],len[x<<1|1]);
	len[x] = max(len[x],R[x<<1]+L[x<<1|1]);
	L[x] = L[x<<1];
	R[x] = R[x<<1|1];
	if(L[x]==llen)L[x]+=L[x<<1|1];
	if(R[x]==rlen)R[x]+=R[x<<1];
}
void build(int x,int l,int r){
	if(l==r){
		len[x] = L[x] = R[x] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x,mid-l+1,r-mid);
}
void update(int x,int l,int r,int pos,int v){
	if(l==r){
		len[x] = L[x] = R[x] = v;
		return;
	}
	int mid = (l+r) >> 1;
	if(pos<=mid){
		update(x<<1,l,mid,pos,v);
	}
	else{
		update(x<<1|1,mid+1,r,pos,v);
	}
	pushup(x,mid-l+1,r-mid);
}
int query(int x,int l,int r,int pos){
	if(len[x] == 0 || len[x] == r-l+1){
		return len[x];
	}
	int mid = (l+r) >> 1;
	if(pos<=mid){
		return pos > mid - R[x<<1] ? R[x<<1] + L[x<<1|1] : query(x<<1,l,mid,pos);
	}
	else{
		return pos <= mid + L[x<<1|1] ? R[x<<1] + L[x<<1|1] : query(x<<1|1,mid+1,r,pos);
	}
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin >> n >> m){
	    stack<int>st;
	    build(1,1,n);
	    while(m--){
	    	string s;
	    	cin >> s;
	    	if(s[0]=='R'){
	    		int now = st.top();
	    		st.pop();
	    		update(1,1,n,now,1);
	    	}
	    	else if(s[0]=='Q'){
	    		int pos;
	    		cin >> pos;
	    		cout << query(1,1,n,pos) << '\n';
	    	}
	    	else{
	    		int pos;
	    		cin >> pos;
	    		update(1,1,n,pos,0);
	    		st.push(pos);
	    	}
	    }
	}
}