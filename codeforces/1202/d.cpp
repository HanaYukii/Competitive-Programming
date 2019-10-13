#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ll cur = 10000;
		int cont[10005] = {};
		f(10000){
			while(n>= cur * (cur-1)/2){
				cont[i]++;
				n -= (cur) * (cur-1) / 2;
			}
			if(!n)break;
			cur--;

		}
		string s;
		f(10000){
			while(cont[i]--){
				s +='7';
			}
			s += '3';
			//cout <<"gg"<<endl;
		}
		s += '1';
		reverse(s.begin(),s.end());
		cout << s << endl;
	}
}