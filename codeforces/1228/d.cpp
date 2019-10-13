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
#define F first
#define S second
const ll mod =998244353;
set<pair<int,int> >st;
int a[3];
bool ok(int i,int j){
    if(i>j)swap(i,j);
    if(st.count({i,j}))return 1;
    return 0;
}
bool check(int num,int g){
    int ret = 1;
    f(3){
        if(i==g)continue;
        ret &= ok(num,a[i]);
    }
    return ret;
}
int main()
{
	int n,m;
	cin >> n >> m;
	if(!m){
		cout<<-1<<endl;
		exit(0);
	}
	vector<pair<int,int> >v;
	f(m){
        int add1,add2;
        cin >> add1 >> add2;
        if(add1>add2)swap(add1,add2);
        v.pb({add1,add2});
        st.insert({add1,add2});
	}
	int vis[n+5] = {};
	unordered_set<int>g[3];
	a[0]=v[0].F;
	a[1]=v[0].S;
	g[0].insert(v[0].F);
	g[1].insert(v[0].S);
	for(int i=1;i<v.size();i++){
        if(v[i].F==v[0].F){
            vis[v[i].S]++;
        }
        else if(v[i].S==v[0].F){
            vis[v[i].F]++;
        }
        if(v[i].F==v[0].S){
            vis[v[i].S]+=2;
        }
        else if(v[i].S==v[0].S){
            vis[v[i].F]+=2;
        }
	}
	f1(n){
        if(vis[i]==3){
            a[2]=i;
            g[2].insert(i);
            break;
        }
	}
	if(!g[2].size()){
        cout<<-1<<endl;
        exit(0);
	}
    int have[n+5] = {};
    have[a[0]]=have[a[1]]=have[a[2]]=1;
    int c[n+5] = {};
    f1(n){
    	if(have[i])continue;
        if(check(i,0)){
            g[0].insert(i);
        }
        else if(check(i,1)){
            g[1].insert(i);
        }
        else if(check(i,2)){
            g[2].insert(i);
        }
        else{
            cout<<-1<<endl;
            exit(0);
        }
    }
    for(auto i:g[0]){
        for(auto j:g[1]){
            if(!st.count({min(i,j),max(i,j)})){
                cout<<-1<<endl;
                exit(0);
            }
            st.erase({min(i,j),max(i,j)});
        }
    }
    for(auto i:g[2]){
        for(auto j:g[1]){
            if(!st.count({min(i,j),max(i,j)})){
                cout<<-1<<endl;
                exit(0);
            }
            st.erase({min(i,j),max(i,j)});
        }
    }
    for(auto i:g[0]){
        for(auto j:g[2]){
            if(!st.count({min(i,j),max(i,j)})){
                cout<<-1<<endl;
                exit(0);
            }
            st.erase({min(i,j),max(i,j)});
        }
    }
    if(st.size()){
        cout<<-1<<endl;
        exit(0);
    }
    for(auto i:g[0]){
        c[i]=1;
    }
    for(auto i:g[1]){
        c[i]=2;
    }
    for(auto i:g[2]){
        c[i]=3;
    }
    f1(n){
        cout<<c[i]<<' ';
    }
    cout << endl;
}
