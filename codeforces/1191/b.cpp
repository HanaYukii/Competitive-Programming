#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 250005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<string>v(3);
	while(cin >> v[0] >> v[1] >> v[2]){
		f(3){
			reverse(v[i].begin(),v[i].end());
		}
		sort(v.begin(),v.end());
		if(v[0] == v[1] && v[1]==v[2]){
			cout<<0<<endl;
		}
		else if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][1]+1 == v[1][1] &&v[1][1] +1 ==v[2][1]){
			cout<<0<<endl;
		}
		else if(v[0]==v[1] || v[1]==v[2]){
			cout<<1<<endl;
		}
		else if(v[0][0] == v[1][0] &&v[0][1]+2 >= v[1][1]){
			cout<<1<<endl;
		}
		else if(v[1][0] == v[2][0] && v[1][1]+2 >= v[2][1]){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
}