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
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >>n){
		int cnt1=0,cnt2=0;
		f(n){
			int add;
			cin >> add;
			if(add==1)cnt1++;
			else cnt2++;
		}
		if(!cnt2){
			f(n){
				cout<<1<<' ';
			}
			cout<<endl;
		}
		else if(!cnt1){
			f(n){
				cout<<2<<' ';
			}
			cout<<endl;
		}
		else{
			cout<<2<<' '<<1<<' ';
			f(cnt2-1){
				cout<<2<<' ';
			}
			f(cnt1-1){
				cout<<1<<' ';
			}
			cout<<endl;
		}
	}

}