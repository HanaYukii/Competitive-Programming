#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans[n+5][n+5] = {};
	ans[1][1] = 1;
	ans[n][n] = 0;
	ans[1][2] = 0;
	for(int i=3;i<=n;i+=2){
		cout<<'?'<<' '<<1<<' '<<i-2<<' '<<1<<' '<<i<<endl;
		int add;
		cin >> add;
		if(add){
			ans[1][i] = ans[1][i-2];
		}
		else{
			ans[1][i] = ans[1][i-2] ^ 1;
		}
	}
	for(int i=4;i<=n;i+=2){
		cout<<'?'<<' '<<1<<' '<<i-2<<' '<<1<<' '<<i<<endl;
		int add;
		cin >> add;
		if(add){
			ans[1][i] = ans[1][i-2];
		}
		else{
			ans[1][i] = ans[1][i-2] ^ 1;
		}
	}
	for(int i=2;i<=n-1;i++){
		if(i%2==0){
			cout<<'?'<<' '<<i-1<<' '<<1<<' '<<i<<' '<<2<<endl;
			int add;
			cin >> add;
			if(!add){
				ans[i][2] = ans[i-1][1] ^ 1;
			}
			else{
				ans[i][2] = ans[i-1][1];
			}
			for(int j=4;j<=n;j+=2){
				cout<<'?'<<' '<<i<<' '<<j-2<<' '<<i<<' '<<j<<endl;
				int add;
				cin >> add;
				if(!add){
					ans[i][j] = ans[i][j-2] ^ 1;
				}
				else{
					ans[i][j] = ans[i][j-2];
				}
			}
		}
		else{
			cout<<'?'<<' '<<i-2<<' '<<1<<' '<<i<<' '<<1<<endl;
			int add;
			cin >> add;
			if(!add){
				ans[i][1] = ans[i-2][1] ^ 1;
			}
			else{
				ans[i][1] = ans[i-2][1];
			}
			for(int j=3;j<=n;j+=2){
				cout<<'?'<<' '<<i<<' '<<j-2<<' '<<i<<' '<<j<<endl;
				int add;
				cin >> add;
				if(!add){
					ans[i][j] = ans[i][j-2] ^ 1;
				}
				else{
					ans[i][j] = ans[i][j-2];
				}
			}
		}
	}
	for(int i=n-2;i>=1;i-=2){
		cout<<'?'<<' '<<n<<' '<<i<<' '<<n<<' '<<i+2<<endl;
		int add;
		cin >> add;
		if(add){
			ans[n][i] = ans[n][i+2];
		}
		else{
			ans[n][i] = ans[n][i+2] ^ 1;
		}
	}
	cout<<'?'<<' '<<1<<' '<<2<<' '<<2<<' '<<3<<endl;
	int add;
	cin >> add;
	if(add){
		ans[2][3]=ans[1][2];
	}
	else{
		ans[2][3]=ans[1][2]^1;
	}
	cout<<'?'<<' '<<2<<' '<<1<<' '<<2<<' '<<3<<endl;
	cin >> add;
	if(add){
		ans[2][1]=ans[2][3];
	}
	else{
		ans[2][1]=ans[2][3]^1;
	}
	for(int j=5;j<=n;j+=2){
		cout<<'?'<<' '<<2<<' '<<j-2<<' '<<2<<' '<<j<<endl;
		int add;
		cin >> add;
		if(!add){
			ans[2][j] = ans[2][j-2] ^ 1;
		}
		else{
			ans[2][j] = ans[2][j-2];
		}
	}
	for(int i=3;i<=n;i++){
		if(i%2){
			cout<<'?'<<' '<<i-1<<' '<<1<<' '<<i<<' '<<2<<endl;
			int add;
			cin >> add;
			if(!add){
				ans[i][2] = ans[i-1][1] ^ 1;
			}
			else{
				ans[i][2] = ans[i-1][1];
			}
			for(int j=4;j<=n;j+=2){
				cout<<'?'<<' '<<i<<' '<<j-2<<' '<<i<<' '<<j<<endl;
				int add;
				cin >> add;
				if(!add){
					ans[i][j] = ans[i][j-2] ^ 1;
				}
				else{
					ans[i][j] = ans[i][j-2];
				}
			}
		}
		else{
			cout<<'?'<<' '<<i-2<<' '<<1<<' '<<i<<' '<<1<<endl;
			int add;
			cin >> add;
			if(!add){
				ans[i][1] = ans[i-2][1] ^ 1;
			}
			else{
				ans[i][1] = ans[i-2][1];
			}
			for(int j=3;j<=n;j+=2){
				cout<<'?'<<' '<<i<<' '<<j-2<<' '<<i<<' '<<j<<endl;
				int add;
				cin >> add;
				if(!add){
					ans[i][j] = ans[i][j-2] ^ 1;
				}
				else{
					ans[i][j] = ans[i][j-2];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x = i+2;
			int y = j +1;
			if(max(x,y)<=n){
				if((ans[i][j]^ans[i+2][j])==(ans[i+1][j]^ans[i+2][j+1])||(ans[i][j]^ans[i+1][j+1])==(ans[i+1][j]^ans[i+2][j+1])||(ans[i][j]^ans[i+1][j+1])==(ans[i][j+1]^ans[i+2][j+1])){
					cout<<'?'<<' '<<i<<' '<<j<<' '<<i+2<<' '<<j+1<<endl;
					int add;
					cin >> add;
					if(add^(ans[i][j]^ans[i+2][j+1])){
						goto endd;
					}
					else{
						goto change;
					}
				}
			}
			x = i + 1;
			y = j + 2;
			if(max(x,y)<=n){
				if((ans[i][j]^ans[i][j+2])==(ans[i][j+1]^ans[i+1][j+2])||(ans[i][j]^ans[i+1][j+1])==(ans[i][j+1]^ans[i+1][j+2])||(ans[i][j]^ans[i+1][j+1])==(ans[i+1][j]^ans[i+1][j+2])){
					cout<<'?'<<' '<<i<<' '<<j<<' '<<i+1<<' '<<j+2<<endl;
					int add;
					cin >> add;
					if(add^(ans[i][j]^ans[i+1][j+2])){
						goto endd;
					}
					else{
						goto change;
					}
				}
			}
			if(j+3<=n){
				if((ans[i][j]^ans[i][j+2])==(ans[i][j+1]^ans[i][j+3])){
					cout<<'?'<<' '<<i<<' '<<j<<' '<<i<<' '<<j+3<<endl;
					int add;
					cin >> add;
					if(add^(ans[i][j]^ans[i][j+3])){
						goto endd;
					}
					else{
						goto change;
					}
				}
			}
			if(i+3<=n){
				if((ans[i][j]^ans[i+2][j])==(ans[i+1][j]^ans[i+3][j])){
					cout<<'?'<<' '<<i<<' '<<j<<' '<<i+3<<' '<<j<<endl;
					int add;
					cin >> add;
					if(add^(ans[i][j]^ans[i+3][j])){
						goto endd;
					}
					else{
						goto change;
					}
				}
			}
		}
	}
	goto endd;
	change:;
	f1(n){
		fr(j,1,n+1){
			if((i+j)%2){
				ans[i][j]^=1;
			}
		}
	}
	endd:;
	cout<<'!'<<'\n';
	f1(n){
		fr(j,1,n+1){
			cout<<ans[i][j];
		}
		cout << '\n';
	}
	cout << endl;
}