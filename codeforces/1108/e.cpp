#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,-1,sizeof(i));
#define pb push_back
const ll mod=998244353;
const int maxn=200005;
int tree[maxn<<2];
int lazy[maxn<<2];
int n,m;

void build(int node=1, int l=1, int r=n)
{
    if(l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    build(node<<1, l, mid);
    build((node<<1)+1, mid+1, r);
    tree[node]=std::max(tree[node<<1], tree[(node<<1)+1]);
}

void pushdown(int node)
{
    if(lazy[node])
    {
        lazy[node<<1]+=lazy[node];
        lazy[(node<<1)+1]+=lazy[node];
        tree[node<<1]+=lazy[node];
        tree[(node<<1)+1]+=lazy[node];
        lazy[node]=0;
    }
}

int g_L,g_R,g_Add;
void change(int node=1, int l=1, int r=n)
{
    if(g_L<=l && r<=g_R)
    {
        tree[node]+=g_Add;  
        lazy[node]+=g_Add; 
        return;
    }
    int mid=(l+r)/2;
    int lc=node<<1;
    int rc=(node<<1)+1;

    pushdown(node); 
    if(g_L<=mid)
        change(lc, l, mid);
    if(g_R>mid)
        change(rc, mid+1, r);
    tree[node]=std::max(tree[lc],tree[rc]); 
}

int query(int node=1, int l=1, int r=n)
{
    if(g_L<=l && r<=g_R)
    {
        return tree[node]; 
    }
    int mid=(l+r)/2;
    int lc=node<<1;
    int rc=(node<<1)+1;
    pushdown(node); 

    int ans=0x80000000;
    if(g_L<=mid)
        ans=std::max(ans, query(lc, l, mid));
    if(g_R>mid)
        ans=std::max(ans, query(rc, mid+1, r));
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	if(n==1){
		cout<<0<<endl<<0<<endl;
		exit(0);
	}
	vector<pair<int,int> >v;
	build();
	f1(n){
		int add;
		cin >> add;
		g_L = i;
		g_R = i;
		g_Add = add;
		change();
	}
	f(m){
		int a,b;
		cin >> a >> b;
		v.pb({a,b});
	}
	int idx=0,mx=0;
	f1(n){
		fr(j,0,m){
			if(v[j].first==i){
				g_L = v[j].first;
				g_R = v[j].second;
				g_Add = -1;
				change();
			}
		}
		int big = -1e6;
		if(i!=1){
			g_L = 1;
			g_R = i-1;
			big = max(big,query());
		}
		if(i!=n){
			g_L = i+1;
			g_R = n;
			big = max(big,query());
		}
		int small;
		g_L = i;
		g_R = i;
		small = query();
		if(big-small>mx){
			mx = big - small;
			idx = i;
		}
		fr(j,0,m){
			if(v[j].second==i){
				g_L = v[j].first;
				g_R = v[j].second;
				g_Add = 1;
				change();
			}
		}
	}
	cout << mx << '\n';
	vector<int>ans;
	for(int i=0;i<m;i++){
		if(v[i].first<=idx&&v[i].second>=idx){
			ans.pb(i+1);
		}
	}
	cout << ans.size() << endl;
	for(auto i:ans){
		cout<<i<<' ';
	}
	cout << endl;
}