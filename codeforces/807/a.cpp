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
	while(cin >> n){
		int f=0;
		vector<int>v,v2;
		f(n){
			int add1, add2;
			cin >> add1 >> add2;
			v.pb(add1);
			v2.pb(add2);
		}
		f(n){
			if(v[i]!=v2[i]){
				cout<<"rated"<<endl;
				exit(0);
			}
			if(i>=1&&v[i]>v[i-1]){
				f=1;
			}
		}
		if(!f){
			cout<<"maybe"<<endl;
		}
		else{
			cout<<"unrated"<<endl;
		}
	}
}