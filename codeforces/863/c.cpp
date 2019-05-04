#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 500005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	while(cin >> n >> a >> b){
		int ta[4][4],tb[4][4];
		pair<int,int>p[50];
		map<pair<int,int>,int>mp
		int pa=0,pb=0;
		f1(3){
			fr(j,1,4){
				cin >> ta[i][j];
			}
		}
		f1(3){
			fr(j,1,4){
				cin >> tb[i][j];
			}
		}
		int turn=0;
		while(mp.find({a,b})==mp.end()){
			if(a==b)pa++,pb++;
			p[turn].first=pa;
			p[turn].second=pb;
			mp[{a,b}]=turn;
			turn++;
			int tta=a,ttb=b;
			a=ta[tta][ttb];
			b=tb[tta][ttb];
		}
		int cycle=mp.size()-mp[{a,b}];
		int ca=p[mp.size()]
	}
	
}