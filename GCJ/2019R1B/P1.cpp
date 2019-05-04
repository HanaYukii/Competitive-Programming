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
struct s
{
	int x,y;
	char d;
}cont[505];
int main()
{
	int t;
	cin >> t;
    for (int c = 1 ;c <= t;c++)
    {
       	int n,q;
       	cin >> n >> q;

       	int16_t cnt[25][25] = {};
       	map<int,int>dis,dis2;
       	map<int,int>rev,rev2;
        f(n){
        	int x,y;
        	char d;
        	cin >> x >> y >> d;
        	cont[i].x=x;
        	cont[i].y=y;
        	cont[i].d=d;
        	dis[x]=0;
        	dis2[y]=0;
        }
        int now=0;
        if(dis.find(0)==dis.end()){
        	dis[0]=0;
        }
        if(dis2.find(0)==dis2.end()){
        	dis2[0]=0;
        }
        set<int>add;
        for(auto i:dis){
        	int ff=i.first;
        	if(dis.find(ff+1)==dis.end()&&ff!=q){
        		add.insert(ff+1);
        	}
        }
        for(auto i:add){
        	dis[i]=0;
        }
        for(auto &i:dis){
        	i.second=now++;
        }
        add.clear();
        now=0;
        for(auto i:dis2){
        	int ff=i.first;
        	if(dis2.find(ff+1)==dis2.end()&&ff!=q){
        		add.insert(ff+1);
        	}
        }
        for(auto i:add){
        	dis2[i]=0;
        }
        for(auto &i:dis2){
        	i.second=now++;
        }
       	for(auto i:dis){
       		rev[i.second]=i.first;
       	}
       	for(auto i:dis2){
       		rev2[i.second]=i.first;
       	}
       	
       	f(n){
       		cont[i].x=dis[cont[i].x];
       		cont[i].y=dis2[cont[i].y];
       	}
       	f(n){
        	int x,y;
        	char d;
        	x=cont[i].x;
        	y=cont[i].y;
        	d=cont[i].d;
        	if(d=='S'){
        		for(int i=0;i<dis.size();i++){
        			for(int j=0;j<y;j++){
        				cnt[i][j]++;
        			}
        		}
        	}
        	else if(d=='N'){
        		for(int i=0;i<dis.size();i++){
        			for(int j=y+1;j<dis2.size();j++){
        				cnt[i][j]++;
        			}
        		}
        	}
        	else if(d=='W'){
        		for(int i=0;i<x;i++){
        			for(int j=0;j<=dis2.size();j++){
        				cnt[i][j]++;
        			}
        		}
        	}
        	else{
        		for(int i=x+1;i<=dis.size();i++){
        			for(int j=0;j<=dis2.size();j++){
        				cnt[i][j]++;
        			}
        		}
        	}
        }
        int xx=0,yy=0,mx=0;
        f(dis.size()){
        	fr(j,0,dis2.size()){
        		//cout<<cnt[i][j]<<' ';
        		if(cnt[i][j]>mx){
        			mx=cnt[i][j];
        			xx=i;
        			yy=j;
        		}
        	}
        	//cout<<endl;
        }
        //cout<<xx<<' '<<yy<<endl;
       	printf("Case #%d: %d %d\n",c,rev[xx],rev2[yy]);
       	
    }
    return 0;
}
