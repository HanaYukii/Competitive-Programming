#include<bits/stdc++.h>
using namespace std;
char s[105];
set<string>e;
string tmp;
int n,m;
set<int>can[105];
int f;
void dfs(int now)
{
    if(f)
        return;
    else if(now==m)
    {
        if(e.find(tmp)==e.end())
        {
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
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
    if(!f)
        cout<<-1<<endl;
}
