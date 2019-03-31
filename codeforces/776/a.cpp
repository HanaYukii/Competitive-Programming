#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;

int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	while(cin >> s1 >> s2){
		int n;
		cin>>n;
		cout<< s1<<' '<<s2<<endl;
		while(n--){
			string s,ss;
			cin >> s >> ss;
			if(s==s1){
				s1=ss;
				cout<<s1<<' '<<s2<<endl;
			}
			else{
				s2=ss;
				cout<<s1<<' '<<s2<<endl;
			}
		}
	}
}