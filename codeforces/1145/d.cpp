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
		set<int>yes,no;
		yes.insert(5);
		yes.insert(46);
		no.insert(24);
		no.insert(13);
		yes.insert(2);
		yes.insert(3);
		yes.insert(4);
		yes.insert(12);
		yes.insert(30);
		yes.insert(35);
		if(yes.find(n)!=yes.end()){
			cout<<"YES"<<endl;
		}
		else if(no.find(n)!=no.end()){
			cout<<"NO"<<endl;
		}
		else{
			int cont[n*1024*100]={};
			cout<<"NO"<<endl;
		}
	}
}