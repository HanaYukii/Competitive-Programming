#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define bg begin()
#define ed end()
#define pii pair<int,int>
ll read(){
    ll n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}
int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int n;
	n=read();
	map<int,int>rem;
	map<int,int>col;
	int ans[100005] = {};
	int nc=1;
	f(n){
		int add;
		cin >> add;
		add = n-1-add;
		if(!add)ans[i]=nc++;
		else if(rem[add]){
			ans[i]=col[add];
			rem[add]--;
		}
		else{
			ans[i]=nc;
			col[add]=nc;
			rem[add]=add;
			nc++;
		}
	}
	for(auto i:rem){
		if(i.second){
			cout<<"Impossible"<<endl;
			exit(0);
		}
	}
	cout<<"Possible"<<endl;
	f(n){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}