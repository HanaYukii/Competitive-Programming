#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 300005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	int n ,k ;
	while(cin >> n){
		int cnt = 0;
		int mx = 1;
		for(int i = 1 ;i <= n ; i++){
			int add;
			cin >> add;
			mx = max(mx,add);
			if(mx <= i){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}