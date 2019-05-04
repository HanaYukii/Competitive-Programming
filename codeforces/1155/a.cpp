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
		string s;
		cin >> s;
		int turn = (n-11)/2;
		int pos=0,cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='8'){
				cnt++;
			}
			if(cnt==turn+1){
				pos=i+1;
				break;
			}
			//cout<<cnt<<endl;
		}
		if(pos==0){
			cout<<"NO"<<endl;
			exit(0);
		}
		cnt=0;
		for(int i=0;i<pos;i++){
			if(s[i]!='8')cnt++;
		}
		//cout<<cnt<<' '<<turn<<endl;
		if(cnt>turn){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}

}