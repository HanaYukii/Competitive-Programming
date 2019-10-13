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
const int mod = 1e9+7;
struct point{
		int x,num;
}w[101000];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	srand(74751);
	clock_t tt = clock();

	while(cin >> n){
		f1(n){
			cin >> w[i].x;
			w[i].num = i;
		}
		
		while(1){
			random_shuffle(w+1,w+n+1);
			int g = 0;
			int sec = 0;
			int cut = 0;
			f1(n){
				g = __gcd(g,w[i].x);
				if(g==1){
					sec++;
					if(cut == 0){
						cut = i;
					}
					g = 0;
				}
			}
			if(sec >= 2){
				cout<<"YES"<<'\n';
				int g[n+5] = {};
				f1(n){
					if(i<=cut){
						g[w[i].num] = 1;
					}
					else{
						g[w[i].num] = 2;
					}
				}
				f1(n){
					cout<<g[i]<<' ';
				}
				cout << '\n';
				exit(0);
			}
			clock_t z = clock() - tt;
			if((double)z/CLOCKS_PER_SEC > 0.48){
				break;
			}
		}
		cout<<"NO"<<endl;
	}		
}