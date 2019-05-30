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

int main(){
	int n;
	while(cin >> n){
		int Min=1e9;
		f(n){
			int add;
			cin >> add;
			if(i==0||i==n-1){
				Min=min(Min,add/(n-1));
			}
			else
				Min=min({Min,add/(i-0),add/(n-1-i)});
		}
		cout << Min << endl;
	}
}