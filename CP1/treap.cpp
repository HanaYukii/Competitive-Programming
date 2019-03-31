#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll unsigned long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ls(x) arr[x].child[0]
#define rs(x) arr[x].child[1]
int flag=0;
pair<ll,ll>lb,rb;
struct node{
	int child[2],key;
	ll size,l,r,range;
}arr[maxn];
int tot;
ll rem;
void pushup(int x){
	arr[x].size=arr[ls(x)].size+arr[rs(x)].size+1;
}
void Spilt(int root,int& x,int& y,ll value){
	if(!root){
		x=y=0;
		return;
	}
	if(arr[root].l<=value)x=root,Spilt(rs(root),rs(x),y,value);
	else y=root,Spilt(ls(root),x,ls(y),value);
	pushup(root);
}
void Merge(int& root,ll x,ll y){
	if(!x||!y){
		root=x+y;
		return;
	}
	if(arr[x].key<arr[y].key){
		root=x;
		Merge(rs(root),rs(x),y);
	}
	else{
		root=y;
		Merge(ls(root),x,ls(y));
	}
	pushup(root);
}
void Insert(int &root,ll l,ll r){
	int x=0,y=0,z=++tot;
	arr[z].l=l;
	arr[z].r=r;
	arr[z].size=r-l+1;
	arr[z].range=r-l+1;
	arr[z].key=rand();
	Spilt(root,x,y,l);
	Merge(x,x,z);
	Merge(root,x,y);
}


ll kth(int root,ll k){
	while(1){
		//cout<<root<<' '<<k<<endl;
		if(arr[ls(root)].size>=k){
			root=ls(root);
			//cout<<1;
		}
		else if(arr[ls(root)].size+arr[root].range<k){
			//cout<<arr[ls(root)].size<<' '<<arr[root].range<<endl;
			//system("PAUSE");
			k-=(arr[ls(root)].size+arr[root].range),root=rs(root);
			//cout<<2;
		}
		else{
			//cout<<3;
			if(!flag){
				lb.first=arr[root].l;
				lb.second=arr[root].r;
			}
			else{
				rb.first=arr[root].l;
				rb.second=arr[root].r;
			}
			return arr[root].l-1+k;
		}
	}
	//return arr[root].value;
}
void Erase(int &root,ll l,ll r){
	int x=0,y=0,z=0;
	//int l=kth(root,k),r=kth(root,min(rem,k+s));
	Spilt(root,x,y,l-1);
	Spilt(y,y,z,r);
	//cout<<l<<' '<<r<<endl;
	Merge(root,x,z);
}


int n,op,root;
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	ll n,k;
	cin>>n>>k;
	Insert(root,1,n);
	rem=n;
	while(k--){
		//cout<<root<<endl;
		cin>>op;
		ll add;
		if(op==1){
			cin>>add;
			cout<<kth(root,add)<<'\n';
		}
		else if(op==2){
			ll k,s;
			cin>>k>>s;
			if(rem<k)continue;
			flag=0;
			ll l=kth(root,k);
			flag=1;
			ll r=kth(root,min(rem,k+s-1));
			rem-=min(s,rem-k+1);
			//cout<<l<<' '<<r<<endl;
			Erase(root,lb.first,rb.first);
			//cout<<lb.first<<' '<<l-1<<endl;
			//cout<<r<<' '<<rb.second<<endl;
			if(lb.first!=l){
				Insert(root,lb.first,l-1);
			}
			if(r!=rb.second){
				Insert(root,r+1,rb.second);
			}
		}
		
	}
}