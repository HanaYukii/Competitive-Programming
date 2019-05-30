#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
const int mod=1e9+7;

int main(){
	int n,x,y;
	cin >> n >> y >> x;
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	int cnt=0;
	for(int i=0;i<y;i++){
		if(i==x&&s[i]=='0')cnt++;
		if(i!=x&&s[i]=='1')cnt++;
	}
	cout<<cnt<<endl;
}