#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define pb push_back
vector<int>g[200005];
int dep[200005];
int v[200005];
int anc[200005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> >e;
    f(n-1){
    	int add1,add2;
    	cin >> add1 >> add2;
    	e.pb({add1,add2});
    	g[add1].pb(add2);
    	g[add2].pb(add1);
    }
    queue<int>q;
    v[1] = 1;
    q.push(1);
    while(!q.empty()){
    	int now=q.front();
    	q.pop();
    	for(auto i:g[now]){
    		if(!v[i]){
    			dep[i] = dep[now] + 1; 
    			v[i] = 1;
    			q.push(i);
    		}
    	}
    }
    f1(n){
    	g[i].clear();
    }
    for(auto i:e){
    	int ff=i.first;
    	int ss=i.second;
    	if(dep[ff]<dep[ss]){
    		g[ff].pb(ss);
    		anc[ss]=ff;
    	}
    	else{
    		g[ss].pb(ff);
    		anc[ff]=ss;
    	}
    }
    int dd;
    cout<<'d'<<' '<<1<<endl;
    cin >> dd;
    vector<int>can;
    f1(n){
    	if(dep[i] == dd){
    		can.pb(i);
    	}
    }
    while(1){
    	random_shuffle(can.begin(),can.end());
    	if(can.size()==1){
    		cout<<'!'<<' '<<can[0]<<endl;
    		exit(0);
    	}
    	cout<<'d'<<' '<<can[0]<<endl;
    	int dis;
    	cin >> dis;
    	if(dis == 0){
    		cout<<'!'<<' '<<can[0]<<endl;
    		exit(0);
    	}
    	dis >>= 1;
    	int pos = can[0];
    	while(dis--){
    		pos = anc[pos];
    	}
    	cout<<'s'<<' '<<pos<<endl;
    	int nxt;
    	cin >> nxt;
    	can.clear();
    	ms(v);
    	queue<int>q;
	    v[nxt] = 1;
	    q.push(nxt);
	    while(!q.empty()){
	    	int now=q.front();
	    	q.pop();
	    	if(dep[now] == dd){
	    		can.pb(now);
	    		continue;
	    	}
	    	for(auto i:g[now]){
	    		if(!v[i]){
	    			dep[i] = dep[now] + 1; 
	    			v[i] = 1;
	    			q.push(i);
	    		}
	    	}
	    }
    }
}