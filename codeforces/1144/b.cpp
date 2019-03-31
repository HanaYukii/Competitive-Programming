#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n){
		multiset<ll>odd,even;
		ll sum = 0;
		f(n){
			ll add;
			cin >> add;
			if(add&1){
				odd.insert(add);
			}
			else{
				even.insert(add);
			}
		}
		if(abs((int)odd.size()-(int)even.size())<=1){
			cout<<0<<endl;
		}
		else{
			int f=0;
			if(even.size()>odd.size()){
				f=1;
			}
			int num=abs((int)even.size()-(int)odd.size())-1;
			int cnt=0;
			if(f){
				for(auto i:even){
					sum += i;
					cnt++;
					if(cnt==num)break;
				}
			}
			else{
				for(auto i:odd){
					sum+=i;
					cnt++;
					if(cnt==num)break;
				}
			}
			cout << sum << endl;
		}
	}


}