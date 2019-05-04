#include<bits/stdc++.h>
using namespace std;
char s[105];
set<string>e;
string tmp;
int n,m;
set<int>can[105];
int f;
int c;
void dfs(int now)
{
    if(f)
        return;
    else if(now==m)
    {
        if(e.find(tmp)==e.end())
        {
            printf("Case #%d: ",c);
            cout<<tmp<<endl;
            f=1;
        }
        return;
    }
    for(int i:can[now])
    {
        tmp[now]='a'+i;
        dfs(now+1);
    }
}
int main()
{
	int t;
	cin >> t;
	for(c=1;c<=t;c++){
		cin>>n>>m;
		f=0;
		for(int i=0;i<m;i++)can[i].clear();
		e.clear();
		for(int i=0;i<n;i++)
	    {
	        cin>>tmp;
	        e.insert(tmp);
	        for(int j=0;j<m;j++)
	        {
	            can[j].insert(tmp[j]-'a');
	        }
	    }
	    dfs(0);
	    /*if(f)
	        cout<<tmp<<endl;*/
	    if(!f)
	        printf("Case #%d: -\n",c);
	}
}