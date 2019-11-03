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
#define F first
#define S second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int x=0,y=0;
    for(auto i:s){
        x<<=1,y<<=1;
        if(i=='0'){

        }
        else if(i=='1'){
            x++;
        }
        else if(i=='2'){
            y++;
        }
        else{
            x++,y++;
        }
    }
    cout<<s.size()<<' '<<x<<' '<<y<<endl;
}
