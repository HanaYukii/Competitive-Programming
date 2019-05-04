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
#define bg begin()
#define ed end()

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n){
		string s;
		cin >> s;
		int l=0,r=0,q=0;
		f(n){
			if(s[i]=='('){
				l++;
			}
			else if(s[i]==')'){
				r++;
			}
			else{
				q++;
			}
		}
		if(n&1){
			cout<<":("<<endl;
			exit(0);
		}
		if(l>n/2||r>n/2){
			cout<<":("<<endl;
			exit(0);
		}
		f(n){
			if(s[i]=='?'&&l<n/2){
				s[i]='(';
				l++;
			}
			else if(s[i]=='?'){
				s[i]=')';
				r++;
			}
		}
		int now=0;
		f(n){
			if(s[i]=='('){
				now++;
			}
			else{
				now--;
			}
			if(now<=0&&i!=n-1){
				cout<<":("<<endl;
				exit(0);
			}
		}
		cout<<s<<endl;
	}

}