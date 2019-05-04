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
using namespace std;

int main()
{
	int t;
	cin >> t;
    for (int ca = 1 ;ca<=t;ca++)
    {
        int n;
        cin >> n;
        int l[105] = {},r[105] = {} ,pos[105] = {};
        int now=1;
        f1(n){
        	int add;
        	cin>>add;
        	if(!add)continue;
        	else{
        		l[i]=now;
        		r[i]=now+add-1;
        		for(int j=now;j<=now+add-1;j++){
        			pos[j]=i;
        		}
        	}
        	now+=add;
        }
        if(!l[1]||!r[n]){
        	printf("Case #%d: IMPOSSIBLE\n",ca);
        	continue;
        }
        int mx=0;
        f1(n){
        	mx=max(mx,abs(pos[i]-i));
        }
        char c[105][105];
        f(mx+1){
        	fr(j,1,n+1){
        		c[i][j]='.';
        	}
        }
        for(int i=2;i<n;i++){
        	if(pos[i]==i)continue;
        	if(pos[i]>i){
        		for(int j=0;j<pos[i]-i;j++){
        			c[j][i+j]='\\';
        		}
        	}
        	else{
        		for(int j=0;j<i-pos[i];j++){
        			c[j][i-j]='/';
        		}
        	}
        }
        printf("Case #%d: %d\n",ca,mx+1);
        f(mx+1){
        	fr(j,1,n+1){
        		cout<<c[i][j];
        	}
        	cout<<endl;
        }
    }
    return 0;
}
