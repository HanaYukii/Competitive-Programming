#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
struct s
{
	int v;
	int idx;
};
bool cmp(s x,s y){
	return x.v > y.v;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<s>v;
	f1(n){
		int add;
		cin >> add;
		v.pb({add,i});
	}
	int ans = 0;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		ans += i*v[i].v;
		ans++;
	}
	cout << ans << endl;
	f(n){
		cout << v[i].idx <<' ';
	}
	cout << endl;
}