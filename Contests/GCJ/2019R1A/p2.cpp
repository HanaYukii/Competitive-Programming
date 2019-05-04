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
	int t,n,m;
	cin >> t >> n >> m;
    for (int c = 1 ;c<=t;c++)
    {
    	int can[1000005]={0};
    	for(int j=0;j<7;j++){
	    	f(18){
	    		cout<<max(3,18-j)<<' ';
	    	}
	    	cout <<endl;
	    	int sum =0;
	    	f1(18){
	    		int add;
	    		cin >> add;
	    		sum +=add;
	    	}
	    	f(m+1){
	    		if(i<sum){
	    			can[i]=1;
	    		}
	    		else if((i-sum)%max(3,18-j)){
	    			can[i]=1;
	    		}
	    	}
	    }
	    f(m+1){
	    	if(!can[i]){
	    		cout<<i<<endl;
	    		break;
	    	}
	    }
	    int v;
	    cin>>v;
	    if(v==-1)exit(0);
	    else continue;
        
    }
    return 0;
}
