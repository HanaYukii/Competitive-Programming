#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define bg begin()
#define ed end()
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	set<int>st;
	int cont[n+5];
	int cnt[n+5]={};
	fr(i,2,n+1){
		int add;
		cin >> add;
		cont[i] = add;
		st.insert(add);
	}
	fr(i,2,n+1){
		if(st.find(i)==st.ed){
			cnt[cont[i]]++;
		}
	}
	int f = 0;
	f1(n){
		if(cnt[i]<3&&st.find(i)!=st.ed){
			f = 1;
		}
	}
	cout<<(f?"No":"Yes")<<endl;
}