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
int inq[1000005] ;
int g[1000005] ;
vector<int>v[1000005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout<<"gg"<<endl;
	int n,op;
	cin >> n >> op;
		ms(inq);
		ms(g);
		queue<int>q;
		
		f1(n)cin >> g[i];
		while(op--){
			int tp;
			cin >> tp;
			if(tp == 1){
				int add;
				cin >> add;
				if(inq[add]){
					cout << "Ignore\n";
				}
				else{
					if(!v[g[add]].size()){
						q.push(g[add]);
					}
					v[g[add]].push_back(add);
					inq[add] = 1;
					cout << "Successful\n" ;
				}
			}
			else{
				if(q.empty()){
					cout << 0 <<'\n';
				}
				else{
					int cur = v[q.front()].back();
					v[q.front()].pop_back();
					cout << cur << '\n';
					inq[cur] = 0;
					if(!v[q.front()].size()){
						q.pop();
					}
					
				}
			}
		}
		//cout << endl;
	
}