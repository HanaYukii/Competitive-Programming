#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define ll long long
#define maxn 400005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
struct e{
	int l;
	int r;
	int idx;
	int f;
}cont[100005];
bool cmp(e x,e y){
	if(x.l!=y.l)
		return x.l<y.l;
	else
		return x.r<y.r;
}
bool cmp2(e x,e y){
	return x.idx<y.idx;
}
int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	while(cin>>n){
		string s[6],ss;
		cin>>ss;
		s[0]="RGB";
		s[1]="RBG";
		s[2]="GRB";
		s[3]="GBR";
		s[4]="BGR";
		s[5]="BRG";
		int Min=1e6,ans=0;
		f(6){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(ss[j]!=s[i][j%3]){
					cnt++;
				}
			}
			if(cnt<Min){
				ans=i;
				Min=cnt;
			}
		}
		cout<<Min<<endl;
		for(int i=0;i<n;i++){
			cout<<s[ans][i%3];
		}
		cout<<endl;
	}
}