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
const ll mod = 1e9+7;
int dp[1000];
int k;
int solve(int x){
	if(dp[x]){
		return dp[x];
	}
	int mi = 1;
	if(x-k>=0){
		mi = min(mi,solve(x-k));
	}
	if(x>=1){
		mi = min(mi,solve(x-1));
	}
	if(x >= 2){
		mi = min(mi,solve(x-2));
	}
	if(mi == -1){
		return dp[x] = 1;
	}
	else{
		return dp[x] = -1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int t;
	cin >> t;
	while(cin >> n >> k){
		/*ms(dp);
		if(solve(n)==-1){
			cout<<"Bob"<<endl;
		}
		else{
			cout<<"Alice"<<endl;
		}*/
		if(n==0){
			cout<<"Bob"<<endl;
		}
		else if(n<3){
			cout<<"Alice"<<endl;
		}
		else{
			if(k%3){
				if(n%3){
					cout<<"Alice"<<endl;
				}
				else{
					cout<<"Bob"<<endl;
				}
			}
			else{
				if(k==3){
					int dif = n-4;
					if(dif%4){
						cout<<"Alice"<<endl;
					}
					else{
						cout<<"Bob"<<endl;
					}
				}
				else{
					int dif = n;
					int cycle = k+1;
					dif %= cycle;
					if(dif != cycle-1 && dif % 3 == 0){
						cout<<"Bob"<<endl;
					}
					else if(dif == 0){
						cout<<"Bob"<<endl;
					}
					else{
						cout<<"Alice"<<endl;
					}
				}
			}
		}
	}
 
}